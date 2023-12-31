// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <cstring>
#include <initializer_list>
#include <iostream>
#include <random>
#include <type_traits>

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

   Matrix(
      std::size_t Rows,
      std::size_t Columns,
      T MinValue,
      T MaxValue);

   Matrix(
      std::size_t Rows,
      std::size_t Columns,
      T Value = T{});

   Matrix(
      const Matrix& Other);

   Matrix(
      Matrix&& Other);

   ~Matrix() { delete[] data_; }

   Matrix<T>&
   operator=(
      const Matrix<T>& Rhs);

   Matrix<T>&
   operator=(
      Matrix<T>&& Rhs);

   std::size_t GetRowsCount() const { return rows_; }

   std::size_t GetColumnsCount() const { return columns_; }

   const T&
   At(
      std::size_t Row,
      std::size_t Column) const;

   T&
   At(
      std::size_t Row,
      std::size_t Column);

   Matrix<T>
   Multiplication_2(
      const Matrix<T>& Rhs);

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

// template <typename T>
// Matrix<T>
// operator * (
//    const Matrix<T>& Lhs,
//    const Matrix<T>& Rhs);


template <typename T>
Matrix<T>
Multiplication_1(
   const Matrix<T>& M1,
   const Matrix<T>& M2);


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
Matrix<T>::Matrix(
   std::size_t Rows,
   std::size_t Columns,
   T MinValue,
   T MaxValue)
   :  rows_{Rows},
      columns_{Columns},
      data_{new T[Rows * Columns]}
{
   std::default_random_engine generator;
   std::conditional_t<
               std::is_floating_point<T>::value,
               std::uniform_real_distribution<T>,
               std::uniform_int_distribution<T>>
   distribution{MinValue, MaxValue};

   for (std::size_t i = 0; i < Rows; ++i)
   {
      for (std::size_t j = 0; j < Columns; ++j)
      {
         std::size_t index = i * Rows + j;
         if (i <= j)
         {
            data_[index] = distribution(generator);
         }
         else
         {
            data_[index] = 0;
         }
      }
   }
}


template <typename T>
Matrix<T>::Matrix(
   std::size_t Rows,
   std::size_t Columns,
   T Value)
   :  rows_{Rows},
      columns_{Columns},
      data_{new T[Rows * Columns]}
{
   for (std::size_t i = 0; i < Rows; ++i)
   {
      for (std::size_t j = 0; j < Columns; ++j)
      {
         std::size_t index = i * Rows + j;
         data_[index] = Value;
      }
   }
}


template <typename T>
Matrix<T>::Matrix(
   const Matrix<T>& Other)
{
   rows_ = Other.rows_;
   columns_ = Other.columns_;
   data_ = new T[rows_ * columns_];
   std::memcpy(data_, Other.data_, sizeof(T) * rows_ * columns_);
}


template <typename T>
Matrix<T>::Matrix(
   Matrix&& Other)
{
   rows_ = Other.rows_;
   columns_ = Other.columns_;
   data_ = Other.data_;
   Other.data_ = nullptr;
}


template <typename T>
Matrix<T>&
Matrix<T>::operator=(
   const Matrix<T>& Rhs)
{
   delete[] data_;

   rows_ = Rhs.rows_;
   columns_ = Rhs.columns_;
   data_ = new T[rows_ * columns_];
   std::memcpy(data_, Rhs.data_, sizeof(T) * rows_ * columns_);

   return *this;
}

template <typename T>
Matrix<T>&
Matrix<T>::operator=(
   Matrix<T>&& Rhs)
{
   rows_ = Rhs.rows_;
   columns_ = Rhs.columns_;
   data_ = Rhs.data_;
   Rhs.data_ = nullptr;

   return *this;
}


template <typename T>
const T&
Matrix<T>::At(
   std::size_t Row,
   std::size_t Column) const
{
   return data_[Row * rows_ + Column];
}


template <typename T>
T&
Matrix<T>::At(
   std::size_t Row,
   std::size_t Column)
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


// template <typename T>
// Matrix<T>
// operator * (
//    const Matrix<T>& Lhs,
//    const Matrix<T>& Rhs)
// {
//    Matrix<T> result(Lhs.GetRowsCount(), Rhs.GetColumnsCount());

//    for (std::size_t i = 0; i < Lhs.GetRowsCount(); ++i)
//    {
//       for (std::size_t j = 0; j < Rhs.GetColumnsCount(); ++j)
//          for (std::size_t z = 0; z < Lhs.GetColumnsCount(); ++z)
//          {
//             result.At(i, j) += Lhs.At(i, z) * Rhs.At(z, j);
//          }
//    }

//    return result;
// }


template <typename T>
Matrix<T>
Multiplication_1(
   const Matrix<T>& Lhs,
   const Matrix<T>& Rhs)
{
   Matrix<T> result(Lhs.GetRowsCount(), Rhs.GetColumnsCount());

   for (std::size_t i = 0; i < Lhs.GetRowsCount(); ++i)
   {
      for (std::size_t j = 0; j < Rhs.GetColumnsCount(); ++j)
      {
         for (std::size_t z = 0; z < Lhs.GetColumnsCount(); ++z)
         {
            result.At(i, j) += Lhs.At(i, z) * Rhs.At(z, j);
         }
      }
   }

   return result;
}


template <typename T>
Matrix<T>
Matrix<T>::Multiplication_2(
   const Matrix<T>& Rhs)
{
   Matrix<T> result(GetRowsCount(), Rhs.GetColumnsCount());

   for (std::size_t i = 0; i < GetRowsCount(); ++i)
   {
      // Адрес на первый элемент в строке.
      T* currentResultBlock = result.data_ + i * GetRowsCount();
      for (std::size_t j = 0; j < Rhs.GetColumnsCount(); ++j)
      {
         currentResultBlock[j] = T{};
      }

      for (std::size_t k = 0; k < Rhs.GetColumnsCount(); ++k)
      {
         T* currentRhsBlock = Rhs.data_ + k * Rhs.GetColumnsCount();
         T currentValueLhs = data_[i * columns_ + k];

         for (std::size_t j = 0; j < Rhs.GetColumnsCount(); ++j)
         {
            currentResultBlock[j] += currentValueLhs * currentRhsBlock[j];
         }
      }

   }

   return result;
}

#endif // __MATRIX_H__