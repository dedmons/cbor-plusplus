#ifndef CBOR_DECODER__H
#define CBOR_DECODER__H

#include <stdint.h>

#include <cbor++/CBORValue.h>

class CBORDecoder {
  public:
    static CBORValue * decodeData(const uint8_t *);
};

#endif /* CBOR_DECODER__H */
