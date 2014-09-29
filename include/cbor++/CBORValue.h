// Copyright (c) 2014 Douglas Edmonson Jr. All rights reserved.
#ifndef CBOR_VALUE__H
#define CBOR_VALUE__H

#include <cstdint>
#include <cstdlib>

#include <string>
#include <vector>
#include <map>

enum CBORType {
  CBORType_PInt,
  CBORType_NInt,
  CBORType_BString,
  CBORType_UString,
  CBORType_Array,
  CBORType_Map,
};

class CBORValue;

typedef std::vector<CBORValue> CBORArray;
typedef std::map<CBORValue,CBORValue> CBORMap;

class CBORValue {
  public:
    CBORValue(const std::uint8_t * bytes);

    CBORValue(const std::uint64_t tag, const std::uint64_t intVal, const bool isNeg);
    CBORValue(const std::uint64_t tag, const std::string * str, const bool isUTF8);
    CBORValue(const std::uint64_t tag, const CBORArray * arr);
    CBORValue(const uint64_t tag, const CBORMap * map);

    bool isType(CBORType type) const;
    bool isPosInteger() const;
    bool isNegInteger() const;
    bool isByteString() const;
    bool isUTF8String() const;
    bool isAarray() const;
    bool isMap() const;

    const uint8_t * getBytes() const;

    uint64_t          getPosInteger() const;
    int64_t           getNegInteger() const;
    const std::string getByteString() const;
    const std::string getUTF8String() const;
    const CBORArray   getAarray() const;
    const CBORMap     getMap() const;

  private:
    CBORType    type;

    bool        isNegative;
    uint64_t    integerValue;
    std::string stringValue;
    CBORArray   arrayValue;
    CBORMap     mapValue;
};

#endif /* CBOR_VALUE__H */
