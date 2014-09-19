#include <cbor++/CBORPlusPlusDecoder.h>

#include <stdio.h>
#include <string.h>


const char *byte_to_bin(uint8_t byte)
{
  static char b[9];
  b[0] = '\0';

  for(int i = 128; i > 0; i >>= 1)
  {
    strcat(b, ((byte&i) == i) ? "1":"0");
  }

  return b;
}

CBORPlusPlusDecoder::CBORPlusPlusDecoder(){}

CBORPlusPlusDecoder::~CBORPlusPlusDecoder(){}

void* CBORPlusPlusDecoder::decodeData(uint8_t* data)
{
  uint8_t byte = *data;

  printf("  input bits: %s\n", byte_to_bin(byte));
  printf("first 3 bits: %s\n", byte_to_bin((byte&0b11100000)>>5));
  printf(" last 5 bits: %s\n", byte_to_bin(byte&0b00011111));

  return NULL;
}
