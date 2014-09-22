#ifndef CBOR_VALUE__H
#define CBOR_VALUE__H

#include <stdint.h>
#include <stdlib.h>

class CBORValue {
  public:
    size_t getSize() const { return size; };
    virtual size_t getBytes(uint8_t * const bytes) const = 0;
    virtual const void * getValue() const = 0;
  protected:
    size_t size;
};

#endif /* CBOR_VALUE__H */
