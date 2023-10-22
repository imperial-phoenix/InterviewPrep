// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <initializer_list>

///////////////////////////////////////////////////////////////////////////////
///                           MATRIX DECLARATION                            ///
///////////////////////////////////////////////////////////////////////////////

template <typename T>
class Matrix
{
public:
   Matrix(
      std::size_t Rows,
      std::size_t Columns,
      std::initializer_list<T> InitList);

   std::size_t GetRowsCount() const { return rows_; }

   std::size_t GetColumnsCount() const { return columns_; }

   const T&
   At(
      std::size_t Row,
      std::size_t Column) const;

private:
   std::size_t rows_;
   std::size_t columns_;
   T* data_;
};


template <typename T>
std::ostream&
operator << (
   std::ostream& Out,
   const Matrix<T>& Matrix);


///////////////////////////////////////////////////////////////////////////////
///                         MATRIX IMPLEMENTATION                           ///
///////////////////////////////////////////////////////////////////////////////

template <typename T>
Matrix<T>::Matrix(
   std::size_t Rows,
   std::size_t Columns,
   std::initializer_list<T> InitList)
   :  rows_{Rows},
      columns_{Columns},
      data_{new T[Rows * Columns]}
{
   std::size_t index = 0;
   for (const T& value : InitList)
   {
      data_[index] = value;
      ++index;
   }

}


template <typename T>
const T&
Matrix<T>::At(
   std::size_t Row,
   std::size_t Column) const
{
   return data_[Row * rows_ + Column];
}


///////////////////////////////////////////////////////////////////////////////

template <typename T>
std::ostream&
operator << (
   std::ostream& Out,
   const Matrix<T>& Matrix)
{
   bool isFirst = true;
   for (std::size_t i = 0; i < Matrix.GetRowsCount(); ++i)
   {
      if (false == isFirst)
      {
         Out << std::endl;
      }

      for (std::size_t j = 0; j < Matrix.GetColumnsCount(); ++j)
      {
         Out << Matrix.At(i, j) << " ";
      }

      isFirst = false;
   }

   return Out;
}

#endif // __MATRIX_H__