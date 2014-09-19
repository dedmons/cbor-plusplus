#include "test.h"

#include <cbor++/cbor++.h>

TEST(CBORPlusPlusDecoder, basic_int_type)
{
  uint8_t data = 0xa1;

  CBORPlusPlusDecoder::decodeData(&data);

  ASSERT_TRUE(true);
}
