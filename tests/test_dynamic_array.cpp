#include <DynamicArray/DynamicArray.h>

#include <gtest/gtest.h>

TEST(DynamicArray, init)
{
  DynamicArray* my_arry = init();
  ASSERT_EQ(my_arry->capacity, 20);
  ASSERT_EQ(my_arry->size, 0);
}


int main(int argc, char **argv) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
