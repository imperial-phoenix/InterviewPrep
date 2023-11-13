// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <algorithm> // Подумать над разделением на апи и реализацию.

namespace Containers {

template <typename T, std::size_t N>
class Array
{
public:
   ////////////////////////////////////////////////////////////////////////////
   ///                             Member types                             ///
   ////////////////////////////////////////////////////////////////////////////

   using value_type              = T;
   using size_type               = std::size_t;
   using difference_type         = std::ptrdiff_t;
   using reference               = value_type&;
   using const_reference         = const value_type&;
   using pointer                 = value_type*;
   using const_pointer           = const value_type*;
   using iterator                = value_type*;
   using const_iterator          = const value_type*;
   using reverse_iterator        = std::reverse_iterator<iterator>;
   using const_reverse_iterator  = std::reverse_iterator<const_iterator>;


   ////////////////////////////////////////////////////////////////////////////
   ///                 Implicitly-defined member functions                  ///
   ////////////////////////////////////////////////////////////////////////////

   // No explicit construct/copy/destroy for aggregate type.


   ////////////////////////////////////////////////////////////////////////////
   ///                             Operations                               ///
   ////////////////////////////////////////////////////////////////////////////

   constexpr
   void
   fill(
      const value_type& value)
   {
      std::fill_n(begin(), size(), value);
   }

   void
   swap(Array& other)
   {
      std::swap_ranges(begin(), end(), other.begin());
   }


   ////////////////////////////////////////////////////////////////////////////
   ///                            Iterators                                 ///
   ////////////////////////////////////////////////////////////////////////////

   iterator
   begin() noexcept
   {
      return data_;
   }

   const_iterator
   begin() const noexcept
   {
      return data_;
   }

   iterator end() noexcept
   {
      return data_ + N;
   }

   const_iterator
   end() const noexcept
   {
      return data_ + N;
   }

   reverse_iterator
   rbegin() noexcept
   {
      return end();
   }

   const_reverse_iterator
   rbegin() const noexcept
   {
      return end();
   }

   reverse_iterator
   rend() noexcept
   {
      return begin();
   }

   reverse_iterator
   rend() const noexcept
   {
      return begin();
   }

   const_iterator
   cbegin() const noexcept
   {
      return data_;
   }

   const_iterator
   cend() const noexcept
   {
      return data_ + N;
   }

   const_iterator
   crbegin() const noexcept
   {
      return end();
   }

   const_iterator
   crend() const noexcept
   {
      return begin();
   }


   ////////////////////////////////////////////////////////////////////////////
   ///                             Capacity                                 ///
   ////////////////////////////////////////////////////////////////////////////

   size_type
   size() const noexcept
   {
      return N;
   }

   size_t
   max_size() const noexcept
   {
      return N;
   }

   bool
   empty() const noexcept
   {
      return 0 == size();
   }


   ////////////////////////////////////////////////////////////////////////////
   ///                            Element access                            ///
   ////////////////////////////////////////////////////////////////////////////

   reference
   operator[](
      size_type Index) noexcept
   {
      return data_[Index];
   }

   const_reference
   operator[](
      size_type Index) const noexcept
   {
      return data_[Index];
   }

   reference
   at(
      size_type Index)
   {
      if (Index >= N)
      {
         throw std::out_of_range("Array::at: Index >= Array size"); // исправить текст сообщения
      }

      return data_[Index];
   }

   const_reference
   at(
      size_type Index) const
   {
      if (Index >= N)
      {
         throw std::out_of_range("Array::at: Index >= Array size"); // исправить текст сообщения
      }

      return data_[Index];
   }

   pointer
   data() noexcept
   {
      return data_;
   }

   const_pointer
   data() const noexcept
   {
      return data_;
   }

   reference
   front() noexcept
   {
      return *begin();
   }

   const_reference
   front() const noexcept
   {
      return *begin();
   }

   reference
   back() noexcept
   {
      return N ? *(end() - 1) : *end();
   }

   const_reference
   back() const noexcept
   {
      return N ? *(end() - 1) : *end();
   }

   T data_[N];
};


///////////////////////////////////////////////////////////////////////////////
///                            Array comparisons                            ///
///////////////////////////////////////////////////////////////////////////////

template <typename T, std::size_t N>
bool
operator==(const Array<T, N>& Lhs, const Array<T, N>& Rhs)
{
   return std::equal(Rhs.begin(), Rhs.end(), Lhs.begin());
}

template <typename T, std::size_t N>
bool
operator!=(const Array<T, N>& Lhs, const Array<T, N>& Rhs)
{
   return !(Lhs == Rhs);
}

template <typename T, std::size_t N>
bool
operator<(const Array<T,N>& Lhs, const Array<T,N>& Rhs)
{
   return std::lexicographical_compare(Lhs.begin(), Lhs.end(), Rhs.begin(), Rhs.end());
}

template <typename T, std::size_t N>
bool
operator>(const Array<T,N>& Lhs, const Array<T,N>& Rhs)
{
   return Rhs < Lhs;
}

template <typename T, std::size_t N>
bool
operator<=(const Array<T,N>& Lhs, const Array<T,N>& Rhs)
{
   return !(Lhs > Rhs);
}

template <typename T, std::size_t N>
bool
operator>=(const Array<T,N>& Lhs, const Array<T,N>& Rhs)
{
   return !(Lhs < Rhs);
}

}


#endif // __ARRAY_H__