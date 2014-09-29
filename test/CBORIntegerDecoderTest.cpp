// Copyright (c) 2014 Douglas Edmonson Jr. All rights reserved.
#include "test.h"

#include <cbor++/CBORValue.h>

#include <cmath>
#include <cstdint>

void testBytesToPosInt(const std::uint8_t * inputData, std::uint64_t expectedValue) {
  CBORValue cborInt = CBORValue::CBORValue(inputData);
  std::uint64_t actual = cborInt.getPosInteger();
  EXPECT_TRUE(cborInt.isType(CBORType_PInt));
  EXPECT_EQ(expectedValue, actual);
}

void testBytesToNegInt(const std::uint8_t * inputData, std::int64_t expectedValue) {
  CBORValue cborInt = CBORValue::CBORValue(inputData);

  std::int64_t actual = cborInt.getNegInteger();
  std::uint64_t actual2 = cborInt.getPosInteger();

  std::int64_t expected2 = labs(expectedValue) - 1;

  EXPECT_TRUE(cborInt.isType(CBORType_NInt));
  EXPECT_EQ(expected2, actual2);
  EXPECT_EQ(expectedValue, actual);
}

void bytesWithInitByteAndData(std::uint8_t ib, std::uint64_t data, std::uint8_t * bytes) {
  memset(bytes, 0, sizeof(std::uint8_t)+sizeof(std::uint64_t));
  memcpy(bytes, &ib, sizeof(ib));
  memcpy(bytes+sizeof(ib), &data, sizeof(data));
}

TEST(CBORInteger, create_positive_int)
{
  std::uint8_t * bytes = (std::uint8_t *)malloc(sizeof(std::uint8_t)+sizeof(std::uint64_t));

  // Test 0x00 -> 0
  bytesWithInitByteAndData(0x00, 0x00, bytes);
  testBytesToPosInt(bytes, 0);

  // Test 0x01 -> 1
  bytesWithInitByteAndData(0x01, 0x00, bytes);
  testBytesToPosInt(bytes, 1);

  // Test 0x0a -> 10
  bytesWithInitByteAndData(0x0a, 0x00, bytes);
  testBytesToPosInt(bytes, 10);

  // Test 0x17 -> 23
  bytesWithInitByteAndData(0x17, 0x00, bytes);
  testBytesToPosInt(bytes, 23);

  // Test 0x1818 -> 24
  bytesWithInitByteAndData(0x18, 0x18, bytes);
  testBytesToPosInt(bytes, 24);

  // Test 0x1819 -> 25
  bytesWithInitByteAndData(0x18, 0x19, bytes);
  testBytesToPosInt(bytes, 25);

  // Test 0x1864 -> 100
  bytesWithInitByteAndData(0x18, 0x64, bytes);
  testBytesToPosInt(bytes, 100);

  // Test 0x1903e8 -> 1,000
  bytesWithInitByteAndData(0x19, 0x03e8, bytes);
  testBytesToPosInt(bytes, 1000);

  // Test 0x1a000f4240 -> 1,000,000
  bytesWithInitByteAndData(0x1a, 0x000f4240, bytes);
  testBytesToPosInt(bytes, 1000000);

  // Test 0x1b000000e8d4a51000 -> 1,000,000,000,000
  bytesWithInitByteAndData(0x1b, 0x000000e8d4a51000, bytes);
  testBytesToPosInt(bytes, 1000000000000);

  // Test 0x1bffffffffffffffff -> 18,446,744,073,709,551,615
  bytesWithInitByteAndData(0x1b, 0xffffffffffffffff, bytes);
  testBytesToPosInt(bytes, 18446744073709551615);

  free(bytes);
}

TEST(CBORDecoder, decode_negative_int)
{
  std::uint8_t * bytes = (std::uint8_t *)malloc(sizeof(std::uint8_t)+sizeof(std::uint64_t));

  // Test 0x20 -> -1
  bytesWithInitByteAndData(0x20, 0x00, bytes);
  testBytesToNegInt(bytes, -1);

  // Test 0x29 -> -10
  bytesWithInitByteAndData(0x29, 0x00, bytes);
  testBytesToNegInt(bytes, -10);

  // Test 0x37 -> -24
  bytesWithInitByteAndData(0x37, 0x00, bytes);
  testBytesToNegInt(bytes, -24);

  // Test 0x3818 -> -25
  bytesWithInitByteAndData(0x38, 0x18, bytes);
  testBytesToNegInt(bytes, -25);

  // Test 0x3863 -> -100
  bytesWithInitByteAndData(0x38, 0x63, bytes);
  testBytesToNegInt(bytes, -100);

  // Test 0x3903e7 -> -1,000
  bytesWithInitByteAndData(0x39, 0x03e7, bytes);
  testBytesToNegInt(bytes, -1000);

  // Test 0x3a000f423f -> -1,000,000
  bytesWithInitByteAndData(0x3a, 0x000f423f, bytes);
  testBytesToNegInt(bytes, -1000000);

  // Test 0x3b000000e8d4a50fff -> -1,000,000,000,000
  bytesWithInitByteAndData(0x3b, 0x000000e8d4a50fff, bytes);
  testBytesToNegInt(bytes, -1000000000000);

  free(bytes);
}
