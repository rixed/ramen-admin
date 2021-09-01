#include <QDebug>

#include "z85.h"

static char const tbl[] {
  "0123456789abcdefghijklmnopqrstuvwxyzABCD"
  "EFGHIJKLMNOPQRSTUVWXYZ.-:+=^!/*?&<>()[]{"
  "}@%$#"
};

static int of_char(char const c)
{
  int p { sizeof(tbl) - 2 };
  while (p > 0 && tbl[p] != c) p--;
  return p;
}

ssize_t z85_decode(size_t const in_len, unsigned char const *in, size_t const out_capa, unsigned char *out)
{
  if (in_len % 5 != 0) {
    qCritical() << "z85_decode: Invalid length for input";
    return -1;
  }

  size_t const out_len { 4 * (in_len / 5) };
  if (out_capa < out_len) {
    qCritical() << "z85_decode: Invalid size:" << out_len << "instead of" << out_capa;
    return -1;
  }

  ssize_t o { 0 };
  for (int i = 0; i < (int)in_len ; i += 5, o += 4) {
    uint32_t n { 0 };
    for (int j = 0; j < 5; j++) {
      int const d { of_char(in[i + j]) };
      if (d < 0) {
        qCritical() << "z85_decode: Invalid character" << in[i + j];
        return -1;
      }
      n = n*85U + (uint32_t)d;
    }
    // Big endian output, assuming little endian for n:
    out[o + 0] = n >> 24;
    out[o + 1] = n >> 16;
    out[o + 2] = n >> 8;
    out[o + 3] = n;
  }

  return o;
}
