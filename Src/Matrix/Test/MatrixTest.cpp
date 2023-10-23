// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include <iostream>

#include "gtest/gtest.h"

#include "Matrix.hpp"

///////////////////////////////////////////////////////////////////////////////
////////////    Matrix<T>::Matrix(std::size_t, std::size_t, T)     ////////////
///////////////////////////////////////////////////////////////////////////////

TEST(MatrixConstructorTest, DefaultValueConstructor)
{
   /*** Arrange ***/
   const std::size_t rows = 3000;
   const std::size_t columns = 3000;

   /*** Act ***/
   Matrix<int> matrix(rows, columns);

   /*** Assert ***/
   EXPECT_EQ(matrix.GetRowsCount(), rows);
   EXPECT_EQ(matrix.GetColumnsCount(), columns);

   for (std::size_t i = 0; i < rows; ++i)
   {
      for (std::size_t j = 0; j < columns; ++j)
      {
         EXPECT_EQ(matrix.At(i,j), int{});
      }
   }
}


TEST(MatrixConstructorTest, SpecifiedValueConstructor)
{
   /*** Arrange ***/
   const std::size_t rows = 3000;
   const std::size_t columns = 3000;
   const int value = 65;

   /*** Act ***/
   Matrix<int> matrix(rows, columns, value);

   /*** Assert ***/
   EXPECT_EQ(matrix.GetRowsCount(), rows);
   EXPECT_EQ(matrix.GetColumnsCount(), columns);

   for (std::size_t i = 0; i < rows; ++i)
   {
      for (std::size_t j = 0; j < columns; ++j)
      {
         EXPECT_EQ(matrix.At(i,j), value);
      }
   }
}


///////////////////////////////////////////////////////////////////////////////
///  Matrix<T>::Matrix(std::size_t, std::size_t, std::initializer_list<T>)  ///
///////////////////////////////////////////////////////////////////////////////

TEST(MatrixConstructorTest, InitListConstructor)
{
   /*** Arrange ***/
   const std::size_t rows = 4;
   const std::size_t columns = 4;
   std::initializer_list<int> initList{
      1,    2,    3,    4,
      5,    6,    7,    8,
      9,    10,   11,   12,
      13,   14,   15,   16
   };

   /*** Act ***/
   Matrix<int> matrix(rows, columns, initList);

   /*** Assert ***/
   EXPECT_EQ(matrix.GetRowsCount(), rows);
   EXPECT_EQ(matrix.GetColumnsCount(), columns);

   int expectedValue = 1;
   for (std::size_t i = 0; i < rows; ++i)
   {
      for (std::size_t j = 0; j < columns; ++j)
      {
         EXPECT_EQ(matrix.At(i,j), expectedValue++);
      }
   }
}


///////////////////////////////////////////////////////////////////////////////
////////////   Matrix<T>::Matrix(std::size_t, std::size_t, T, T)   ////////////
///////////////////////////////////////////////////////////////////////////////

TEST(MatrixConstructorTest, UpperTriangularMatrixConstructor)
{
   /*** Arrange ***/
   const std::size_t rows = 3000;
   const std::size_t columns = 3000;
   const int minValue = 100;
   const int maxValue = 1000;

   /*** Act ***/
   Matrix<int> matrix(rows, columns, minValue, maxValue);

   /*** Assert ***/
   EXPECT_EQ(matrix.GetRowsCount(), rows);
   EXPECT_EQ(matrix.GetColumnsCount(), columns);

   for (std::size_t i = 0; i < rows; ++i)
   {
      for (std::size_t j = 0; j < columns; ++j)
      {
         int value = matrix.At(i, j);
         if (i <= j)
         {
            EXPECT_GE(value, minValue);
            EXPECT_LE(value, maxValue);
         }
         else
         {
            EXPECT_EQ(value, 0);
         }
      }
   }
}


///////////////////////////////////////////////////////////////////////////////
//////////////////////////////        main       //////////////////////////////
///////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}