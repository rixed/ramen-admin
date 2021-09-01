#ifndef Z85_H_210831
#define Z85_H_210831

ssize_t z85_decode(size_t const in_len, unsigned char const *in,
                   size_t const out_capa, unsigned char *out);

#endif
