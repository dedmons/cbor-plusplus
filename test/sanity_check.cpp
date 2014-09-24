/*
 * Copyright (c) 2014 Douglas Edmonson Jr. All rights reserved.
 *
 * This is an example unit test that doesn't really do anything useful.
 * It is here as a reference for you when creating additional unit tests.
 * For additional reference information, see the "test.h" header.
 */

#include "test.h" // Brings in the test frameworks

using ::testing::ElementsAreArray;
using ::testing::DoubleNear;

TEST(sanity_check, basics) // Declares a test named "sanity_check"
{
  ASSERT_TRUE(true); // We certainly hope that true is true
  ASSERT_EQ(2,1+1);  // The value 1+1 should equal 2
}

TEST(sanity_check, arrays)
{
  int x[] = {1,2,3};
  int y[] = {1,2,3};
  ASSERT_THAT(x,ElementsAreArray(y,3)); // These arrays of length 3 are equal
}

TEST(sanity_check, doubles)
{
  double a = 1.51;
  double b = 1.52;
  ASSERT_THAT(a,DoubleNear(b,0.1)); // These equal within 0.1
}
