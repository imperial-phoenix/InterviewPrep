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
////////////////      Matrix<T>::Matrix(const Matrix<T>&)      ////////////////
///////////////////////////////////////////////////////////////////////////////

TEST(MatrixConstructorTest, CopyConstructor)
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

   Matrix firstMatrix{rows, columns, initList};

   /*** Act ***/
   Matrix secondMatrix{firstMatrix};

   /*** Assert ***/
   EXPECT_EQ(firstMatrix.GetRowsCount(), secondMatrix.GetRowsCount());
   EXPECT_EQ(firstMatrix.GetColumnsCount(), secondMatrix.GetColumnsCount());

   for (std::size_t i = 0; i < rows; ++i)
   {
      for (std::size_t j = 0; j < columns; ++j)
      {
         EXPECT_EQ(secondMatrix.At(i,j), firstMatrix.At(i, j));
      }
   }
}


///////////////////////////////////////////////////////////////////////////////
//////////////////       Matrix<T>::Matrix(Matrix<T>&&)       //////////////////
///////////////////////////////////////////////////////////////////////////////

TEST(MatrixConstructorTest, MoveConstructor)
{
   /*** Arrange ***/
   const std::size_t rows = 100;
   const std::size_t columns = 250;
   const int value = 55;
   Matrix firstMatrix{rows, columns, value};

   /*** Act ***/
   Matrix secondMatrix{std::move(firstMatrix)};

   /*** Assert ***/
   EXPECT_EQ(rows, secondMatrix.GetRowsCount());
   EXPECT_EQ(columns, secondMatrix.GetColumnsCount());

   for (std::size_t i = 0; i < rows; ++i)
   {
      for (std::size_t j = 0; j < columns; ++j)
      {
         EXPECT_EQ(secondMatrix.At(i,j), value);
      }
   }
}


///////////////////////////////////////////////////////////////////////////////
///////////    Matrix<T>& Matrix<T>::operator=(const Matrix<T>&)    ///////////
///////////////////////////////////////////////////////////////////////////////

TEST(MatrixOperatorsTest, CopyAssignmentOperator)
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

   Matrix firstMatrix{rows, columns, initList};
   Matrix<int> secondMatrix{rows, columns};

   /*** Act ***/
   secondMatrix = firstMatrix;

   /*** Assert ***/
   EXPECT_EQ(firstMatrix.GetRowsCount(), secondMatrix.GetRowsCount());
   EXPECT_EQ(firstMatrix.GetColumnsCount(), secondMatrix.GetColumnsCount());

   for (std::size_t i = 0; i < rows; ++i)
   {
      for (std::size_t j = 0; j < columns; ++j)
      {
         EXPECT_EQ(secondMatrix.At(i,j), firstMatrix.At(i, j));
      }
   }
}


///////////////////////////////////////////////////////////////////////////////
//////////////    Matrix<T>& Matrix<T>::operator=(Matrix<T>&)    //////////////
///////////////////////////////////////////////////////////////////////////////

TEST(MatrixOperatorsTest, MoveAssignmentOperator)
{
   /*** Arrange ***/
   const std::size_t rows = 4;
   const std::size_t columns = 4;
   const int value = 55;

   Matrix firstMatrix{rows, columns, value};

   /*** Act ***/
   Matrix secondMatrix = std::move(firstMatrix);

   /*** Assert ***/
   EXPECT_EQ(secondMatrix.GetRowsCount(), rows);
   EXPECT_EQ(secondMatrix.GetColumnsCount(), columns);

   for (std::size_t i = 0; i < rows; ++i)
   {
      for (std::size_t j = 0; j < columns; ++j)
      {
         EXPECT_EQ(secondMatrix.At(i,j), value);
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