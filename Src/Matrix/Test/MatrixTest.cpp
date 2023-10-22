// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include <iostream>

#include "Matrix.hpp"


int main()
{
   Matrix matrix{2, 2, {1, 2, 3, 4}};
   std::cout << matrix << std::endl;
}