#include <cbor++/CBORValue.h>

#include <cmath>

#include "util.h"

union uint_conv_u{
  uint8_t  byte[8];
  uint8_t  i8;
  uint16_t i16;
  uint32_t i32;
  uint64_t i64;
} uint_conv;

uint64_t getInteger(const uint8_t * bytes, uint8_t count)
{
  for(int i = 0; i < count; i++){
    //printf("Setting byte %d to 0x%02x\n", i, bytes[i]);
    uint_conv.byte[i] = bytes[i];
  }

  switch(count){
  case 1:
    return uint_conv.i8;
    break;
  case 2:
    return uint_conv.i16;
    break;
  case 4:
    return uint_conv.i32;
    break;
  case 8:
    return uint_conv.i64;
    break;
  }
  return 0;
}

/*************************
 *
 * Constructors
 *
 *************************/
CBORValue::CBORValue(const uint8_t * bytes)
{
  uint8_t typeByte = *bytes;

  uint8_t mt = getMajorType(typeByte);
  uint8_t ai = getAdditionalInfo(typeByte);

  switch(mt) {
  case CBORType_PInt:
    type = CBORType_PInt;
    isNegative = false;
    if(ai <= 23) {
      integerValue = ai;
    } else {
      const uint8_t * data = bytes + sizeof(uint8_t);
      uint8_t count = pow(2,ai-24);
      integerValue = getInteger(data, count);
    }
    break;
  case CBORType_NInt:
    type = CBORType_NInt;
    isNegative = true;
    if(ai <= 23) {
      integerValue = ai;
    } else {
      const uint8_t * data = bytes + sizeof(uint8_t);
      uint8_t count = pow(2,ai-24);
      integerValue = getInteger(data, count);
    }
    break;
  case CBORType_BString:
  case CBORType_UString:
  case CBORType_Array:
  case CBORType_Map:
  default:
    break;
  }
}

/*************************
 *
 * Type Checks
 *
 *************************/
bool CBORValue::isType(CBORType t) const
{
  return type == t;
}

bool CBORValue::isPosInteger() const
{
  return isType(CBORType_PInt);
}

bool CBORValue::isNegInteger() const
{
  return isType(CBORType_NInt);
}

/*************************
 *
 * Value Accessors
 *
 *************************/
uint64_t CBORValue::getPosInteger() const
{
  return integerValue;
}

int64_t CBORValue::getNegInteger() const
{
  return -1 - integerValue;
}
