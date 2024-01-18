#include "vector/vector.h"

#include "gtest/gtest.h"

class VectorTest : public testing::Test
{
  virtual void SetUp() override{

  }

  virtual void TearDown() override {

  }
};

TEST(VectorTest, vector_constructor_default)
{
  Vector<int> vec;
  ASSERT_EQ(vec.size(), 0);
  ASSERT_EQ(vec.capacity(), 3);
};

TEST(VectorTest, vector_copyFrom)
{
  Vector<int> vec(4, 2, 2);
  Vector<int> vec_copy(vec);

  ASSERT_EQ(vec_copy.size(), 2);
  ASSERT_EQ(vec_copy.capacity(), 4);
};



int main(int argc, char **argv) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
