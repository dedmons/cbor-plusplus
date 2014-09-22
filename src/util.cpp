#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const char *byte_to_bin(uint8_t byte, int bits)
{
  static bool allocated = false;
  static char *b;
  if(!allocated){
    free(b);
  }

  b = (char *)malloc(sizeof(char)*bits);
  allocated = true;

  b[0] = '\0';

  for(int i = 1 << (bits-1); i > 0; i >>= 1)
  {
    strcat(b, ((byte&i) == i) ? "1":"0");
  }

  return b;
}
