#ifndef STUN_PACKET_H
#define STUN_PACKET_H

#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <stdlib.h>

namespace stun {
enum {
  STUN_HEADER_SIZE = 20,
  STUN_MAGIC_COOKIE = 0x2112A442,
  STUN_BINDING_METHOD = 1,
  STUN_SHARED_SECRET_METHOD = 2,
  STUN_ALLOCATE_METHOD = 3,
  STUN_REFRESH_METHOD = 4,
  STUN_SEND_METHOD = 6,
  STUN_DATA_METHOD = 7,
  STUN_CHANNEL_BIND_METHOD = 9,
  STUN_REQUEST_CLASS = 0,
  STUN_INDICATION_CLASS = 1,
  STUN_SUCCESS_CLASS = 2,
  STUN_ERROR_CLASS = 3,
};

typedef struct {
  char *buf;
  int ofs;
  int size;
  int len;
} PACKET;

int packet_init(PACKET *m, char *buf, int buf_size) {
  m->buf = buf;
  m->size = buf_size;
  m->len = 0;
  m->ofs = 0;
  return 0;
}

int packet_write(PACKET *m, int v) {
  if (m && m->ofs < m->size - 1) {
    m->buf[m->ofs++] = v & 0xff;

    if (m->len < m->ofs) m->len++;

    return 1;
  }
  return 0;
}

#define w8(m, v) packet_write(m, v & 0xff)
#define w16(m, v) w8(m, v >> 8) + w8(m, v)
#define w32(m, v) w16(m, v >> 16) + w16(m, v)
#define w64(m, v) w32(m, v >> 32) + w32(m, v)
#define wBuf(m, buf, len)                         \
  {                                               \
    int k = 0, i = 0;                             \
    for (i = 0; i < len; i++) k += w8(m, buf[i]); \
  }

void random_data(char *buf, int a, int b, int len) {
  int i;
  for (i = 0; i < len; i++) buf[i] = a + rand() % (b - a);
}

void stun_write_header(PACKET *m, int type) {
  char tsx_id[12];
  random_data(tsx_id, 0, 0xff, 12);
  w16(m, type);
  w16(m, 0);
  w32(m, STUN_MAGIC_COOKIE);
  wBuf(m, tsx_id, 12);
}

void stun_write_footer(PACKET *m) {
  m->ofs = 2;
  w16(m, m->len - STUN_HEADER_SIZE);
}
}  // namespace stun

#endif  // STUN_PACKET_H
