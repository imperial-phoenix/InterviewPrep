#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
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
int
Nod(int a, int b)
{
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

   return a + b;
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


/**
 * @brief Задание по программированию «Автобусные остановки — 1».
*/
void BusManager1()
{
   std::map<std::string, std::vector<std::string>> busStops; // остановки автобуса
   std::map<std::string, std::vector<std::string>> stopBuses; // автобусы остановки

   int q = 0;
   std::cin >> q;

   for (int i = 0; i < q; ++i)
   {
      std::string operationCode;
      std::cin >> operationCode;

      if ("NEW_BUS" == operationCode)
      {
         std::string bus;
         int stopCount;

         std::cin >> bus >> stopCount;
         for (int i = 0; i < stopCount; ++i)
         {
            std::string stop;
            std::cin >> stop;

            busStops[bus].push_back(stop);
            stopBuses[stop].push_back(bus);
         }
      }
      else if ("BUSES_FOR_STOP" == operationCode)
      {
         std::string stop;
         std::cin >> stop;

         if (stopBuses.count(stop) == 0)
         {
            std::cout << "No stop" << std::endl;
         }
         else
         {
            for (const auto& bus : stopBuses[stop])
            {
               if (stopBuses[stop].back() != bus)
                  std::cout << bus << " ";
               else
                  std::cout << bus;
            }
            std::cout << std::endl;
         }
      }
      else if ("STOPS_FOR_BUS" == operationCode)
      {
         std::string bus;
         std::cin >> bus;

         if (busStops.count(bus) == 0)
         {
            std::cout << "No bus" << std::endl;
         }
         else
         {
            for (const auto& stop : busStops[bus])
            {
               std::cout << "Stop " << stop << ":";

               if (stopBuses[stop].size() == 1)
               {
                  std::cout << " no interchange" << std::endl;
               }
               else
               {
                  for (const auto& stopBus : stopBuses[stop])
                  {
                     if (bus != stopBus)
                        std::cout << " " << stopBus;
                  }
                  std::cout << std::endl;
               }
            }
         }
      }
      else if ("ALL_BUSES" == operationCode)
      {
         if (busStops.empty())
         {
            std::cout << "No buses" << std::endl;
         }
         else
         {
            for (const auto& bus : busStops)
            {
               std::cout << "Bus " << bus.first << ":";
               for (const auto& stop : bus.second)
                  std::cout << " " << stop;
               std::cout << std::endl;
            }
         }
      }
   }
}


///////////////////////////////////////////////////////////////////////////////
///            Задание по программированию «Имена и фамилии — 2»            ///
///////////////////////////////////////////////////////////////////////////////

// Если имя (фамилия) неизвестно, возвращает пустую строку
std::string FindNameByYear(const std::map<int, std::string>& names, int year)
{
  std::string name; // изначально имя неизвестно

   // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
   for (const auto& item : names)
   {
      // если очередной год не больше данного, обновляем имя
      if (item.first <= year)
      {
         name = item.second;
      }
      else
      {
         // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
         break;
      }
   }

   return name;
}


std::string GetNameWithHistory(const std::map<int, std::string>& names, int year)
{
   std::string name;
   std::vector<std::string> all_names;

   for (auto& item : names)
   {
      if (year >= item.first)
         all_names.push_back(item.second);
      else
         break;
   }

   if (all_names.empty())
   {
      return "";
   }

   // Удаляем подряд стоящие одинаковые имена
   auto last = std::unique(all_names.begin(), all_names.end());
   all_names.erase(last, all_names.end());

   // if (all_names.size() > 1)
   // {
   //    auto it = all_names.rbegin();
   //    name = *it++;
   //    name += " (";
   //    for (; it != all_names.rend(); ++it)
   //    {
   //       if (it + 1 != all_names.rend())
   //          name += *it + ", ";
   //       else
   //          name += *it;
   //    }
   //    name += ")";
   // }
   // else if (all_names.size() == 1)
   // {
   //    name = all_names.front();
   // }

   std::reverse(all_names.begin(), all_names.end());
   name = all_names[0];

   for (int i = 1; i < all_names.size(); ++i)
   {
      if (1 == i)
      {
         name += " (";
      }
      else
      {
         name += ", ";
      }

      name += all_names[i];
   }

   if (all_names.size() > 1)
   {
      name += ")";
   }

   return name;
}


std::string BuildFullName(const std::string& first_name, const std::string& last_name) {
  if (first_name.empty() && last_name.empty()) {
    return "Incognito";
  } else if (first_name.empty()) {
    return last_name + " with unknown first name";
  } else if (last_name.empty()) {
    return first_name + " with unknown last name";
  } else {
    return first_name + " " + last_name;
  }
}


class Person
{
public:
   Person(const std::string& FirstName, const std::string& LastName, int BirthYear)
   {
      birthYear = BirthYear;
      names[BirthYear] = FirstName;
      last_names[BirthYear] = LastName;
   }


   void ChangeFirstName(int year, const std::string& first_name)
   {
      if (year >= birthYear)
      {
         names[year] = first_name;
      }

   }


   void ChangeLastName(int year, const std::string& last_name)
   {
      if (year >= birthYear)
      {
         last_names[year] = last_name;
      }

   }


   std::string GetFullName(int year) const
   {
      if (year < birthYear)
      {
         return "No person";
      }

      std::string current_first_name = FindNameByYear(names, year);
      std::string current_last_name = FindNameByYear(last_names, year);

      // std::string full_name;
      // if (current_first_name.empty() && current_last_name.empty())
      //    full_name = "Incognito";
      // else if (current_first_name.empty())
      //    full_name = current_last_name + " with unknown first name";
      // else if (current_last_name.empty())
      //    full_name = current_first_name + " with unknown last name";
      // else
      //    full_name = current_first_name + " " + current_last_name;

      // return full_name;

      return BuildFullName(current_first_name, current_last_name);
   }


   std::string GetFullNameWithHistory(int year) const
   {
      if (year < birthYear)
      {
         return "No person";
      }

      std::string current_first_name = GetNameWithHistory(names, year);
      std::string current_last_name = GetNameWithHistory(last_names, year);

      // std::string full_name;
      // if (current_first_name.empty() && current_last_name.empty())
      //    full_name = "Incognito";
      // else if (current_first_name.empty())
      //    full_name = current_last_name + " with unknown first name";
      // else if (current_last_name.empty())
      //    full_name = current_first_name + " with unknown last name";
      // else
      //    full_name = current_first_name + " " + current_last_name;

      // return full_name;

      return BuildFullName(current_first_name, current_last_name);
   }

private:
   std::map<int, std::string> names;
   std::map<int, std::string> last_names;
   int birthYear;
};


struct Specialization
{
   explicit Specialization(const std::string& Specialization)
   {
      specialization_ = Specialization;
   }

   std::string specialization_;
};


struct Course
{
   explicit Course(const std::string& Course)
   {
      course_ = Course;
   }

   std::string course_;
};


struct Week
{
   explicit Week(const std::string& Week)
   {
      week_ = Week;
   }

   std::string week_;
};


struct LectureTitle
{
   LectureTitle(const Specialization& Specialization,
                const Course& Course,
                const Week& Week) : specialization{Specialization}, course{Course}, week{Week} {}

   Specialization specialization;
   Course course;
   Week week;
};


///////////////////////////////////////////////////////////////////////////////

class FunctionPart
{
public:
   FunctionPart(char newOperation, double newValue)
   {
      operation = newOperation;
      value = newValue;
   }

   double Apply(double sourceValue) const
   {
      if ('+' == operation)
      {
         return sourceValue + value;
      }
      else if ('-' == operation)
      {
         return sourceValue - value;
      }
      else if ('*' == operation)
      {
         return sourceValue * value;
      }
      else if ('/' == operation)
      {
         return sourceValue / value;
      }
   }

   void Invert()
   {
      if ('+' == operation)
      {
         operation = '-';
      }
      else if ('-' == operation)
      {
         operation = '+';
      }
      else if ('*' == operation)
      {
         operation = '/';
      }
      else if ('/' == operation)
      {
         operation = '*';
      }
   }

private:
   char operation;
   double value;
};


class Function
{
public:
   void AddPart(char operation, double value)
   {
      parts.push_back({operation, value});
   }

   double Apply(double value) const
   {
      for (const FunctionPart& part : parts)
      {
         value = part.Apply(value);
      }
      return value;
   }

   void Invert()
   {
      for (FunctionPart& part : parts)
      {
         part.Invert();
      }

      std::reverse(parts.begin(), parts.end());
   }

private:;
   std::vector<FunctionPart> parts;
};


#include <iostream>
using namespace std;

class Rational
{
public:
   Rational()
   {
      p_ = 0;
      q_ = 1;
   }


   Rational(int p, int q)
   {
      if (p == 0)
      {
         q = 1;
      }

      if (p < 0 && q < 0)
      {
         p = abs(p);
         q = abs(q);
      }
      else if (p > 0 && q < 0)
      {
         q = abs(q);
         p = -p;
      }
      // if (q < 0)
      // {
      //    p = -p;
      //    q = -q;
      // }


      int nod = Nod(p, q);

      p_ = p / nod;
      q_ = q / nod;
   }




   int Numerator() const
   {
      return p_;
   }


   int Denominator() const
   {
      return q_;
   }

private:
   int p_;
   int q_;
};


int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

   {
        const Rational r(-8, 24);
        if (r.Numerator() != -1 || r.Denominator() != 3) {
            cout << "Rational(-8, 24) != -1/3" << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
