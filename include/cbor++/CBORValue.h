#ifndef CBOR_VALUE__H
#define CBOR_VALUE__H

#include <stdint.h>
#include <stdlib.h>

#include <string.h>
#include <vector.h>
#include <map.h>

enum CBORType {
  CBORType_PInt,
  CBORType_NInt,
  CBORType_BString,
  CBORType_UString,
  CBORType_Array,
  CBORType_Map,
}

typedef std::vector<CBORValue> CBORArray
typedef std::map<CBORValue,CBORValue> CBORMap

class CBORValue {
  public:
    CBORValue(const uint8_t * bytes);

    CBORValue(const uint64_t tag, const uint64_t pInt);
    CBORValue(const uint64_t tag, const int64_t nInt);
    CBORValue(const uint64_t tag, const char * bStr);
    CBORValue(const uint64_t tag, const std::string * uStr);
    CBORValue(const uint64_t tag, const CBORArray * arr);
    CBORValue(const uint64_t tag, const CBORMap * map);

    bool isType(CBORType type) const;
    bool isPosInteger() const;
    bool isNegInteger() const;
    bool isByteString() const;
    bool isUTF8String() const;
    bool isAarray() const;
    bool isMap() const;

    const uint8_t * getBytes() const;

    uint64_t getPosInteger() const;
    int64_t getNegInteger() const;
    const char * getByteString() const;
    const std::string getUTF8String() const;
    const CBORArray getAarray() const;
    const CBORMap getMap() const;

  private:
    CBORType type;
};

#endif /* CBOR_VALUE__H */
