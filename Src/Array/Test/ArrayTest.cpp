// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include <array>
#include <iostream>

#include "gtest/gtest.h"

#include "Array.hpp"


TEST(ArrayConstructorTest, ImplicitCtor)
{
   /*** Arrange ***/
   // Containers::Array<int, 5> array{1, 2, 3, 4, 5};

   /*** Act ***/

   /*** Assert ***/
}


///////////////////////////////////////////////////////////////////////////////
//////////////////////////////        main       //////////////////////////////
///////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}