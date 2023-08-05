#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>


/**
* @brief Решение квадратного уравнения.
*/
void
SolveQuadraticEquation()
{
   /*
    * Алгоритм решения квадратного уравнения:
    * 1) Проверить является ли уравнение квадратным.
    * 2) Вычислить дискриминант D квадратного уравнения.
    * 3) Если D < 0, то уравнение не имеет корней.
    * 4) Если D = 0, то уравнение имеет два одинаковых корня.
    * 5) Если D > 0, то уравнение имеет два корня.
   */  

   double a, b, c;
   std::cin >> a >> b >> c;

   if (0 == a) // линейное уравнение Bx + C = 0
   {
      if (b != 0) // Bx = -C => x = -C / B
      {
         std::cout << -c / b << std::endl;
      }
      else
      {
         //std::cout << "Уравнение не имеет корней." << std::endl;
      }
   }
   else // квадратное уравнение
   {
      double d = b * b - 4 * a * c;

      if (0 == d) // уравнение имеет один корень
      {
         std::cout << -b / (2 * a) << std::endl;
      }
      else if (d > 0)
      {
         std::cout << (-b + std::sqrt(d)) / (2 * a) <<
               " " << (-b - std::sqrt(d)) / (2 * a) << std::endl;   
      }
      else
      {
         //std::cout << "Уравнение не имеет действительных корней." << std::endl;
      }
   }
   
}


/**
* @brief Находит наибольший общий делитель двух чисел.
*/
void
Nod()
{
   int a, b;
   std::cin >> a >> b;

   while (a > 0 && b > 0)
   {
      if (a > b)
      {
         a = a % b;
      }
      else
      {
         b = b % a;
      }
   }

   std::cout << a + b << std::endl;
}


/**
* @brief Перевод числа из десятичной системы в двочную.
*/
void
DecToBin()
{
   int dec;
   std::cin >> dec;

   std::vector<int> bin;
   while (dec)
   {
      bin.push_back(dec % 2);
      dec = dec / 2;
   }

   std::reverse(bin.begin(), bin.end());   

   for (auto item : bin)
   {
      std::cout << item;
   }
}


/**
* @brief Вычисление факториала
*/
int
Factorial(
   int Number)
{
   if (Number <= 1) { return 1; }

   int res = 1;
   for (int i = 2; i <= Number; ++i)
   {
      res *= i;
   }

   return res;
}


int main()
{
   int a;
   std::cin >> a;
   std::cout << Factorial(a) << std::endl;   

   return 0;
}
