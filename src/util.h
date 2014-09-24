// Copyright (c) 2014 Douglas Edmonson Jr. All rights reserved.
#ifndef UTIL__H
#define UTIL__H

const char *byte_to_bin(uint8_t byte, int bits);

inline uint8_t getMajorType(const uint8_t data) { return data >> 5; };

inline uint8_t getAdditionalInfo(const uint8_t data) { return data & 0x1f; };

#endif /* UTIL__H */
