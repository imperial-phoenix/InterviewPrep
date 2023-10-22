#include <iostream>

#include "../Matrix.hpp"

int main()
{
   Matrix matrix{2, 2, {1, 2, 3, 4}};
   std::cout << matrix << std::endl;
}