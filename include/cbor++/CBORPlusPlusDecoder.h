#ifndef CBORPLUSPLUS__H
#define CBORPLUSPLUS__H

#include <cstdint>

class CBORPlusPlusDecoder {
  public:
    CBORPlusPlusDecoder();
    ~CBORPlusPlusDecoder();
    static void* decodeData(uint8_t*);
};

#endif /* CBORPLUSPLUS__H */
