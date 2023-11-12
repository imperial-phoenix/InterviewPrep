// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include <array>
#include <iostream>

#include "gtest/gtest.h"

#include "Array.hpp"


TEST(ArrayTest, ImplicitCtor)
{
   /*** Arrange ***/
   const std::size_t size = 5;
   int expected[size]{1, 2, 3, 4, 5};

   /*** Act ***/
   Containers::Array<int, 5> array{1, 2, 3, 4, 5};

   /*** Assert ***/
   EXPECT_EQ(memcmp(expected, array.data(), sizeof(int) * size), 0);
}

TEST(ArrayTest, ZeroArray)
{
   /*** Arrange ***/
   const std::size_t size = 0;

   /*** Act ***/
   Containers::Array<int, size> array;

   /*** Assert ***/
   EXPECT_EQ(array.size(), 0);
   EXPECT_EQ(array.begin(), array.end());
}

TEST(ArrayTest, RandomAccess)
{
   /*** Arrange ***/
   const std::size_t size = 5;
   std::string expected[size]{
      "one",
      "two",
      "free",
      "four",
      "five"
   };

   /*** Act ***/
   Containers::Array<std::string, size> array;
   std::copy(std::begin(expected), std::end(expected), std::begin(array));

   /*** Assert ***/
   EXPECT_EQ(size, array.size());

   for (std::size_t i = 0; i < array.size(); ++i)
   {
      EXPECT_EQ(expected[i], array[i]);
      EXPECT_EQ(expected[i], array.at(i));
   }

   // Проверка генерации исключения при неправильном доступе.
   EXPECT_THROW(array.at(size), std::out_of_range);
}

TEST(ArrayTest, FrontAndBackAccess)
{
   /*** Arrange ***/
   const std::size_t size = 5;
   std::string expected[size]{
      "one",
      "two",
      "free",
      "four",
      "five"
   };

   /*** Act ***/
   Containers::Array<std::string, size> array;
   std::copy(std::begin(expected), std::end(expected), std::begin(array));

   /*** Assert ***/
   EXPECT_EQ(expected[0], array.front());
   EXPECT_EQ(expected[size - 1], array.back());
}


TEST(ArrayTest, ComparisonOperators)
{
   /*** Arrange ***/
   Containers::Array<int, 5> arr1{1, 2, 3, 4, 5};
   Containers::Array<int, 5> arr2{1, 2, 3, 4, 5};
   Containers::Array<int, 5> arr3{5, 4, 3, 2, 1};

   /*** Act && Assert ***/
   EXPECT_EQ(arr1, arr2);
   EXPECT_NE(arr1, arr3);

   EXPECT_GT(arr3, arr1);
   EXPECT_LT(arr1, arr3);
}



///////////////////////////////////////////////////////////////////////////////
//////////////////////////////        main       //////////////////////////////
///////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}