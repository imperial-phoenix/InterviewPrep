// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include <iostream>

#include "gtest/gtest.h"

#include "Matrix.hpp"

TEST(MyTestSuite, MyTestCase)
{
   ASSERT_EQ(1, 1);
}

int main(int argc, char** argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}