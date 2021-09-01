#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sodium.h>

static void dump(char const *label, unsigned char const *d, size_t len)
{
  printf("%s: ", label);
  for (size_t i = 0; i < len; i++) {
    printf("0x%x,", d[i]);
  }
  printf("\n");
}

static void check_eq(char *label, unsigned char *exp, unsigned char *act, size_t sz)
{
  if (memcmp(exp, act, sz) == 0) {
    printf("%s: OK!\n", label);
  } else {
    printf("%s: FAILED!\n", label);
    dump("Expected", exp, sz);
    dump("But got ", act, sz);
    exit(1);
  }
}

int main(void)
{
  if (sodium_init() < 0) {
    printf("Cannot initialize libsodium!?\n");
    return 1;
  }

  // Copied from runtime:
  unsigned char clear[54] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,5,114,105,120,101,100,0,0,0,0,0,192,114,64, };
  unsigned char nonce[24] = { 38,172,149,173,27,108,94,55,139,112,148,8,136,99,175,198,181,124,178,50,194,108,10,199, };
  unsigned char srv_pub_key[32] = { 126,104,73,163,121,165,181,235,1,239,47,249,112,115,175,90,90,91,133,6,44,119,186,129,224,4,248,173,80,103,192,52, };
  unsigned char clt_priv_key[32] = { 53,152,64,142,201,77,218,110,36,246,77,63,164,156,166,13,30,168,251,114,154,228,23,169,239,59,254,103,16,95,241,154, };
  unsigned char clt_pub_key[32] = { 169,191,32,49,117,10,91,135,225,0,232,133,189,8,61,130,95,66,24,62,243,38,223,60,33,92,183,233,6,215,220,91, };
  unsigned char crypted[54] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,23,96,214,193,185,143,141,101,12,177,97,41,49,187,239,4,242,230,59,95,128,124,194,94,137,206,30,240,68,226,184,157,186,253,139,197,161,216, };
  unsigned char srv_crypted[38] = { 23,96,214,193,185,143,141,101,12,177,97,41,49,187,239,4,242,230,59,95,128,124,194,94,137,206,30,240,68,226,184,157,186,253,139,197,161,216, };
  unsigned char srv_nonce[] = { 38,172,149,173,27,108,94,55,139,112,148,8,136,99,175,198,181,124,178,50,194,108,10,199, };
  unsigned char srv_clt_pub_key[] = { 169,191,32,49,117,10,91,135,225,0,232,133,189,8,61,130,95,66,24,62,243,38,223,60,33,92,183,233,6,215,220,91, };
  unsigned char srv_srv_priv_key[] = { 134,149,82,141,166,179,163,234,122,85,161,8,111,188,211,92,73,43,210,248,222,206,2,71,1,253,68,35,19,146,31,101, };
  unsigned char srv_srv_pub_key[] = { 126,104,73,163,121,165,181,235,1,239,47,249,112,115,175,90,90,91,133,6,44,119,186,129,224,4,248,173,80,103,192,52, };

  unsigned char act_crypted[sizeof crypted];
  assert(srv_pub_key[0] == 126);
  assert(srv_srv_pub_key[0] == 126);
  if (crypto_box(act_crypted, clear, sizeof clear, nonce, srv_pub_key, clt_priv_key) < 0) {
    printf("Cannot decrypt\n");
    return -1;
  }
  assert(srv_pub_key[0] == 126);
  assert(srv_srv_pub_key[0] == 126);

  check_eq("Encrypted", crypted, act_crypted, sizeof crypted);

  assert(sizeof nonce == sizeof srv_nonce);
  check_eq("Nonce", nonce, srv_nonce, sizeof nonce);
  assert(sizeof srv_pub_key == sizeof srv_srv_pub_key);
  check_eq("Srv pub key", srv_pub_key, srv_srv_pub_key, sizeof srv_pub_key);
  assert(sizeof clt_pub_key == sizeof srv_clt_pub_key);
  check_eq("Clt pub key", clt_pub_key, srv_clt_pub_key, sizeof clt_pub_key);
  assert(sizeof crypted == sizeof srv_crypted + crypto_box_BOXZEROBYTES);
  check_eq("Cypher text", crypted + crypto_box_BOXZEROBYTES, srv_crypted, sizeof srv_crypted);

  // Test decryption:

  /* First: simply using crypto_box_open: */
  unsigned char m1[sizeof crypted];
  assert(crypto_box_BOXZEROBYTES <= sizeof crypted);
  bzero(crypted, crypto_box_BOXZEROBYTES);
  int ret = crypto_box_open(m1, crypted, sizeof crypted, nonce, srv_clt_pub_key, srv_srv_priv_key);
  if (ret != 0) {
    printf("Cannot crypto_box_open!\n");
    return -1;
  }
  printf("Decrypting with crypto_box_open: OK!\n");

  /* sess.peer_pub_key <- Some peer_pub_key ;
     sess.channel_key <- Some (Box.precompute sess.my_priv_key peer_pub_key)
     Box.Bytes.fast_box_open (Option.get sess.channel_key) bytes nonce */
  assert(sizeof srv_clt_pub_key == crypto_box_PUBLICKEYBYTES);
  assert(sizeof srv_srv_priv_key == crypto_box_SECRETKEYBYTES);
  unsigned char chan_k[crypto_box_BEFORENMBYTES];
  ret = crypto_box_beforenm(chan_k, srv_clt_pub_key, srv_srv_priv_key);
  if (ret != 0) {
    printf("Cannot crypto_box_beforenm!\n");
    return -1;
  }

  unsigned char m2[sizeof crypted];
  assert(crypto_box_BOXZEROBYTES <= sizeof crypted);
  bzero(crypted, crypto_box_BOXZEROBYTES);
  ret = crypto_box_open_afternm(m2, crypted, sizeof crypted, nonce, chan_k);
  if (ret != 0) {
    printf("Cannot crypto_box_open_afternm!\n");
    return -1;
  }
  printf("Decrypting with crypto_box_open_afternm: OK!\n");

  return 0;
}
