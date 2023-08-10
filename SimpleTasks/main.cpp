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
* @brief Вычисление факториала.
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


/**
* @brief Проверяет является ли слово палиндромом.
*/
bool
IsPalindrom(
   std::string Str)
{
   bool res = true;

   for (size_t i = 0; i < Str.size() / 2; ++i)
   {
      if (Str[i] != Str[Str.size() - i - 1])
      {
         res = false;
         break;
      }
   }

   return res;
}


void
YandexQueue()
{
   int q = 0;
   std::cin >> q;

   std::vector<bool> queue;
   
   for (int i = 0; i < q; ++i)
   {
      std::string operationCode;
      std::cin >> operationCode;

      if ("COME" == operationCode)
      {
         int size = 0;
         std::cin >> size;

         queue.resize(queue.size() + size, false);
      }
      else if ("WORRY" == operationCode)
      {
         int index = 0;
         std::cin >> index;
         queue[index] = true;
      }
      else if ("QUIET" == operationCode)
      {
         int index = 0;
         std::cin >> index;
         queue[index] = false;
      }
      else if ("WORRY_COUNT" == operationCode)
      {
         std::cout << std::count(std::begin(queue), std::end(queue), true) << std::endl;
      }
   }

}


void
TaskManager()
{
   std::vector<int> daysInMonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   int indexCurrentMonth = 0;
   int daysInCurrentMonth = daysInMonth[indexCurrentMonth];
   std::vector<std::vector<std::string>> toDoList(daysInCurrentMonth);

   int q = 0;
   std::cin >> q;

   for (int i = 0; i < q; ++i)
   {
      std::string operationCode;
      std::cin >> operationCode;

      if ("ADD" == operationCode)
      {
         int dayIndex = 0;
         std::cin >> dayIndex;
         --dayIndex;

         std::string task;
         std::cin >> task;

         toDoList[dayIndex].push_back(task);
      }
      else if ("DUMP" == operationCode)
      {
         int dayIndex = 0;
         std::cin >> dayIndex;
         --dayIndex;

         std::cout << toDoList[dayIndex].size() << " ";
         for (auto deal : toDoList[dayIndex])
         {
            std::cout << deal << " ";
         }
         std::cout << std::endl;
      }
      else if ("NEXT" == operationCode)
      {
         indexCurrentMonth = (indexCurrentMonth + 1 ) % 12;
         int daysInNextMonth = daysInMonth[indexCurrentMonth];

         if (daysInNextMonth < daysInCurrentMonth)
         {
            for (int i = daysInNextMonth; i < daysInCurrentMonth; ++i)
            {
               toDoList[daysInNextMonth - 1].insert(toDoList[daysInNextMonth - 1].end(), toDoList[i].begin(), toDoList[i].end());
            }
         }

         toDoList.resize(daysInNextMonth);

         daysInCurrentMonth = daysInNextMonth;
      }
   }

}


int main()
{
   TaskManager();

   return 0;
}
