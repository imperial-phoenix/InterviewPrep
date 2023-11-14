// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <algorithm> // Подумать над разделением на апи и реализацию.

namespace Containers {

////////////////////////////////////////////////////////////////////////////
//////////////////////////////   DECLARATION   /////////////////////////////
////////////////////////////////////////////////////////////////////////////

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
   ///                              Operations                              ///
   ////////////////////////////////////////////////////////////////////////////

   void
   fill(
      const value_type& value);

   void
   swap(
      Array& other);


   ////////////////////////////////////////////////////////////////////////////
   ///                            Iterators                                 ///
   ////////////////////////////////////////////////////////////////////////////


   iterator
   begin() noexcept;

   const_iterator
   begin() const noexcept;

   iterator end() noexcept;

   const_iterator
   end() const noexcept;

   reverse_iterator
   rbegin() noexcept;

   const_reverse_iterator
   rbegin() const noexcept;

   reverse_iterator
   rend() noexcept;

   reverse_iterator
   rend() const noexcept;

   const_iterator
   cbegin() const noexcept;

   const_iterator
   cend() const noexcept;

   const_iterator
   crbegin() const noexcept;

   const_iterator
   crend() const noexcept;


   ////////////////////////////////////////////////////////////////////////////
   ///                             Capacity                                 ///
   ////////////////////////////////////////////////////////////////////////////

   size_type
   size() const noexcept;

   size_t
   max_size() const noexcept;

   bool
   empty() const noexcept;


   ////////////////////////////////////////////////////////////////////////////
   ///                            Element access                            ///
   ////////////////////////////////////////////////////////////////////////////

   reference
   operator[](
      size_type Index) noexcept;

   const_reference
   operator[](
      size_type Index) const noexcept;

   reference
   at(
      size_type Index);

   const_reference
   at(
      size_type Index) const;

   pointer
   data() noexcept;

   const_pointer
   data() const noexcept;

   reference
   front() noexcept;

   const_reference
   front() const noexcept;

   reference
   back() noexcept;

   const_reference
   back() const noexcept;

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


////////////////////////////////////////////////////////////////////////////
////////////////////////////   IMPLEMENTATION   ////////////////////////////
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
///                             Member types                             ///
////////////////////////////////////////////////////////////////////////////

template <typename T, std::size_t N>
void Array<T,N>::fill(const value_type& value)
{
   std::fill_n(begin(), size(), value);
}

template <typename T, std::size_t N>
void Array<T,N>::swap(Array<T,N>& other)
{
   std::swap_ranges(begin(), end(), other.begin());
}


////////////////////////////////////////////////////////////////////////////
///                            Iterators                                 ///
////////////////////////////////////////////////////////////////////////////

template <typename T, std::size_t N>
Array<T,N>::iterator
Array<T,N>::begin() noexcept
{
   return data_;
}

template <typename T, std::size_t N>
Array<T,N>::const_iterator
Array<T,N>::begin() const noexcept
{
   return data_;
}

template <typename T, std::size_t N>
Array<T,N>::iterator Array<T,N>::end() noexcept
{
   return data_ + N;
}

template <typename T, std::size_t N>
Array<T,N>::const_iterator
Array<T,N>::end() const noexcept
{
   return data_ + N;
}

template <typename T, std::size_t N>
Array<T,N>::reverse_iterator
Array<T,N>::rbegin() noexcept
{
   return end();
}

template <typename T, std::size_t N>
Array<T,N>::const_reverse_iterator
Array<T,N>::rbegin() const noexcept
{
   return end();
}

template <typename T, std::size_t N>
Array<T,N>::reverse_iterator
Array<T,N>::rend() noexcept
{
   return begin();
}

template <typename T, std::size_t N>
Array<T,N>::reverse_iterator
Array<T,N>::rend() const noexcept
{
   return begin();
}

template <typename T, std::size_t N>
Array<T,N>::const_iterator
Array<T,N>::cbegin() const noexcept
{
   return data_;
}

template <typename T, std::size_t N>
Array<T,N>::const_iterator
Array<T,N>::cend() const noexcept
{
   return data_ + N;
}

template <typename T, std::size_t N>
Array<T,N>::const_iterator
Array<T,N>::crbegin() const noexcept
{
   return end();
}

template <typename T, std::size_t N>
Array<T,N>::const_iterator
Array<T,N>::crend() const noexcept
{
   return begin();
}


////////////////////////////////////////////////////////////////////////////
///                             Capacity                                 ///
////////////////////////////////////////////////////////////////////////////

template <typename T, std::size_t N>
Array<T,N>::size_type
Array<T,N>::size() const noexcept
{
   return N;
}

template <typename T, std::size_t N>
size_t
Array<T,N>::max_size() const noexcept
{
   return N;
}

template <typename T, std::size_t N>
bool
Array<T,N>::empty() const noexcept
{
   return 0 == size();
}


////////////////////////////////////////////////////////////////////////////
///                            Element access                            ///
////////////////////////////////////////////////////////////////////////////

template <typename T, std::size_t N>
Array<T,N>::reference
Array<T,N>::operator[](
   size_type Index) noexcept
{
   return data_[Index];
}

template <typename T, std::size_t N>
Array<T,N>::const_reference
Array<T,N>::operator[](
   size_type Index) const noexcept
{
   return data_[Index];
}

template <typename T, std::size_t N>
Array<T,N>::reference
Array<T,N>::at(
   size_type Index)
{
   if (Index >= N)
   {
      throw std::out_of_range("Array::at: Index >= Array size"); // исправить текст сообщения
   }
   return data_[Index];
}

template <typename T, std::size_t N>
Array<T,N>::const_reference
Array<T,N>::at(
   size_type Index) const
{
   if (Index >= N)
   {
      throw std::out_of_range("Array::at: Index >= Array size"); // исправить текст сообщения
   }
   return data_[Index];
}

template <typename T, std::size_t N>
Array<T,N>::pointer
Array<T,N>::data() noexcept
{
   return data_;
}

template <typename T, std::size_t N>
Array<T,N>::const_pointer
Array<T,N>::data() const noexcept
{
   return data_;
}

template <typename T, std::size_t N>
Array<T,N>::reference
Array<T,N>::front() noexcept
{
   return *begin();
}

template <typename T, std::size_t N>
Array<T,N>::const_reference
Array<T,N>::front() const noexcept
{
   return *begin();
}

template <typename T, std::size_t N>
Array<T,N>::reference
Array<T,N>::back() noexcept
{
   return N ? *(end() - 1) : *end();
}

template <typename T, std::size_t N>
Array<T,N>::const_reference
Array<T,N>::back() const noexcept
{
   return N ? *(end() - 1) : *end();
}

}


#endif // __ARRAY_H__