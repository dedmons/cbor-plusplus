#include "test.h"

#include <cbor++/cbor++.h>

void testDataToInt(uint8_t data)
{
  static const char * cborIntName = typeid(CBORInteger).name();
  CBORValue * cborInt = CBORDecoder::decodeData(&data);
  const char * actualName = "Not Found";
  try {
    actualName = typeid(*cborInt).name();
  } catch(const std::bad_typeid& e) {

  }
  EXPECT_STREQ(cborIntName, actualName) << "Type ID invalid for " << std::hex << int(data);
  free(cborInt);
}

TEST(CBORDecoder, decode_positive_int)
{
  uint8_t data[11] = {
    0x00,
    0x01,
    0x0a,
    0x17,
    0x18,
    0x19,
    0x1a,
    0x1b
  };

  for(int i = 0; i < 11; i++){
    testDataToInt(data[i]);
  }
}

TEST(CBORDecoder, decode_negative_int)
{
  uint8_t data[7] = {
    0x20,
    0x21,
    0x37,
    0x38,
    0x39,
    0x3a,
    0x3b
  };

  for(int i = 0; i < 7; i++){
    testDataToInt(data[i]);
  }
}
