// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#ifndef __ARRAY_H__
#define __ARRAY_H__

namespace Containers {

template <typename T, std::size_t N>
class Array
{
public:
   using value_type        = T;
   using size_type         = std::size_t;
   using difference_type   = std::ptrdiff_t;
   using reference         = value_type&;
   using const_reference   = const value_type&;
   using pointer           = value_type*;
   using const_pointer     = const value_type*;

   operator[](size_type Index)
   {
      return data_[Index];
   }


   T data_[N];
};

}


#endif // __ARRAY_H__