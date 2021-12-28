// vim: sw=2 ts=2 sts=2 expandtab tw=80
#ifndef Z85_H_210831
#define Z85_H_210831
extern "C" {
#include <sys/types.h>
}

ssize_t z85_decode(size_t const in_len, unsigned char const *in,
                   size_t const out_capa, unsigned char *out);

#endif
