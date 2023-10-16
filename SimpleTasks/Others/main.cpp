#include <algorithm>
#include <cmath>
#include <exception>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <tuple>
#include <utility>


/**
* @brief Решение квадратного уравнения.
*/
void
SolveQuadraticEquation(double a, double b, double c)
{
   /*
    * Алгоритм решения квадратного уравнения:
    * 1) Проверить является ли уравнение квадратным.
    * 2) Вычислить дискриминант D квадратного уравнения.
    * 3) Если D < 0, то уравнение не имеет корней.
    * 4) Если D = 0, то уравнение имеет два одинаковых корня.
    * 5) Если D > 0, то уравнение имеет два корня.
   */

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


///////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class Rational
{
public:
   Rational()
   {
      num_ = 0;
      den_ = 1;
   }


   Rational(int num, int den)
   {
      if (0 == den)
      {
         throw std::invalid_argument("Invalid argument");
      }

      if (num == 0)
      {
         den = 1;
      }

      if (den < 0)
      {
         num = -num;
         den = -den;
      }

      int nod = Nod(abs(num), den);

      num_ = num / nod;
      den_ = den / nod;
   }


   int Numerator() const
   {
      return num_;
   }


   int Denominator() const
   {
      return den_;
   }

private:
   int num_;
   int den_;
};

Rational Reduce(const Rational& rational)
{
   int nod = Nod(rational.Numerator(), rational.Denominator());

   return Rational(rational.Numerator() / nod, rational.Denominator() / nod);
}


bool operator==(const Rational& lhs, const Rational& rhs)
{
   return (lhs.Denominator() == rhs.Denominator() && lhs.Numerator() == rhs.Numerator());
}


Rational operator+(const Rational& lhs, const Rational& rhs)
{
   return Rational(lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
}


Rational operator-(const Rational& lhs, const Rational& rhs)
{
   return Rational(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
}


Rational operator*(const Rational& lhs, const Rational& rhs)
{
   return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
   if (rhs.Numerator() == 0)
   {
      throw std::domain_error("Division by zero");
   }
   return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}


std::ostream& operator<<(std::ostream& out, const Rational& r)
{
   out << r.Numerator() << "/" << r.Denominator();
   return out;
}

std::istream& operator>>(std::istream& in, Rational& r)
{
   int num;
   int den;
   char c;
   in >> num >> c >> den;
   if (in && c == '/')
   {
      r = Rational(num, den);
   }
   // else
   // {
   //    throw std::invalid_argument("Invalid argument");
   // }

   return in;
}

bool operator<(const Rational& lhs, const Rational& rhs)
{
   return (lhs.Numerator() * rhs.Denominator()) < (rhs.Numerator() * lhs.Denominator());
}

///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <exception>
#include <string>
using namespace std;

string AskTimeServer() {
    /* Для тестирования повставляйте сюда код, реализующий различное поведение этой функии:
       * нормальный возврат строкового значения
       * выброс исключения system_error
       * выброс другого исключения с сообщением.
    */

   throw std::runtime_error("Server error");
}

class TimeServer {
public:
    string GetCurrentTime() {
        /* Реализуйте этот метод:
            * если AskTimeServer() вернула значение, запишите его в last_fetched_time и верните
            * если AskTimeServer() бросила исключение system_error, верните текущее значение
            поля last_fetched_time
            * если AskTimeServer() бросила другое исключение, пробросьте его дальше.
        */

      try
      {
         last_fetched_time = AskTimeServer();
      }
      catch (std::system_error& system_error)
      {

      }

      return last_fetched_time;
    }

private:
    string last_fetched_time = "00:00:00";
};


/////////////////// Шаблонный вывод контейнеров vector, map ///////////////////

template <typename Container>
std::string
Join(Container& C)
{
   std::stringstream ss;
   bool isFirst = true;
   for (const auto& item : C)
   {
      if (!isFirst)
      {
         ss << ",";
      }
      isFirst = false;
      ss << item;
   }

   return ss.str();
}


template <typename T>
std::ostream& operator<< (std::ostream& Out, const std::vector<T>& V)
{
   return Out << "[" << Join(V) << "]";
}


template <typename First, typename Second>
std::ostream& operator<< (std::ostream& Out, const std::pair<First, Second>& P)
{
   return Out << "(" << P.first << ", " << P.second << ")";
}


template <typename Key, typename Value>
std::ostream& operator<< (std::ostream& Out, const std::map<Key, Value>& M)
{
   return Out << "{" << Join(M) << "}";
}


///////////////////////////////////////////////////////////////////////////////

template <typename T>
T Sqr(const T& X);

template <typename First, typename Second>
std::pair<First, Second> Sqr(const std::pair<First, Second>& Pair);

template <typename T>
std::vector<T> Sqr(const std::vector<T>& Vector);

template <typename Key, typename Value>
std::map<Key, Value> Sqr(const std::map<Key, Value>& Map);


template <typename T>
T Sqr(const T& X)
{
   return X * X;
}


template <typename First, typename Second>
std::pair<First, Second> Sqr(const std::pair<First, Second>& Pair)
{
   return std::make_pair(Sqr(Pair.first), Sqr(Pair.second));
}


template <typename T>
std::vector<T> Sqr(const std::vector<T>& Vector)
{
   std::vector<T> result;

   for (const T& item : Vector)
   {
      result.push_back(Sqr(item));
   }

   return result;
}


template <typename Key, typename Value>
std::map<Key, Value> Sqr(const std::map<Key, Value>& Map)
{
   std::map<Key, Value> result;

   for (const auto& pair : Map)
   {
      result[pair.first] = Sqr(pair.second);
   }

   return result;
}

///////////////////////////////////////////////////////////////////////////////
///                            Тестовый фреймворк                           ///
///////////////////////////////////////////////////////////////////////////////

template <typename T, typename U>
void
AssertEqual(
   const T& t,
   const U& u,
   const std::string& hint)
{
   if (t != u)
   {
      std::ostringstream oss;
      oss << "Assertion failed: " << t << " != " << u << " hint: " << hint;
      throw std::runtime_error(oss.str());
   }
}

inline void Assert(bool b, const std::string& hint)
{
   AssertEqual(b, true, hint);
}

class TestRunner
{
public:
   template <typename TestFunc>
   void RunTest(TestFunc func, const std::string& test_name)
   {
      try
      {
         func();
         std::cerr << test_name << " OK" << std::endl;
      }
      catch (std::runtime_error& ex)
      {
         ++fail_count;
         std::cerr << test_name << " fail: " << ex.what() << std::endl;
      }
   }

   ~TestRunner()
   {
      if (fail_count > 0)
      {
         std::cerr << fail_count << " unit tests failed. Terminate." << std::endl;
         exit(1);
      }
   }

private:
   int fail_count = 0;
};

///////////////////////////////////////////////////////////////////////////////


// Перечислимый тип для статуса задачи
enum class TaskStatus {
   NEW,
   IN_PROGRESS,
   TESTING,
   DONE
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
   // Получить статистику по статусам задач конкретного разработчика
   const TasksInfo& GetPersonTasksInfo(const string& person) const;

   // Добавить новую задачу (в статус NEW) для конкретного разработчика
   void AddNewTask(const string& person);

   // Обновить статусы по данному количеству задач конкретного разработчика
   tuple<TasksInfo, TasksInfo>
   PerformPersonTasks(
      const string& person,
      int task_count);

// private:
   std::map<std::string, TasksInfo> data_;
};


void
TeamTasks::AddNewTask(
   const string& person)
{
   data_[person][TaskStatus::NEW] += 1;
}


const TasksInfo&
TeamTasks::GetPersonTasksInfo(
               const string& person) const
{
   return data_.at(person);
}


void RemoveZeroValue(TasksInfo& Map)
{
   if (Map[TaskStatus::NEW] == 0)
   {
      Map.erase(TaskStatus::NEW);
   }
   if (Map[TaskStatus::IN_PROGRESS] == 0)
   {
      Map.erase(TaskStatus::IN_PROGRESS);
   }
   if (Map[TaskStatus::TESTING] == 0)
   {
      Map.erase(TaskStatus::TESTING);
   }
   if (Map[TaskStatus::DONE] == 0)
   {
      Map.erase(TaskStatus::DONE);
   }
}


tuple<TasksInfo, TasksInfo>
TeamTasks::PerformPersonTasks(
               const string& person,
               int task_count)
{
   TasksInfo updatedTasks;
   TasksInfo actualTasks = data_[person];
   TasksInfo untouchedTasks = data_[person];

   while (task_count)
   {
      if (untouchedTasks.count(TaskStatus::NEW) > 0 && untouchedTasks[TaskStatus::NEW] > 0)
      {
         updatedTasks[TaskStatus::IN_PROGRESS] += 1;
         untouchedTasks[TaskStatus::NEW] -= 1;
         actualTasks[TaskStatus::NEW] -= 1;
         actualTasks[TaskStatus::IN_PROGRESS] += 1;
      }
      else if (untouchedTasks.count(TaskStatus::IN_PROGRESS) > 0 && untouchedTasks[TaskStatus::IN_PROGRESS] > 0)
      {
         updatedTasks[TaskStatus::TESTING] += 1;
         untouchedTasks[TaskStatus::IN_PROGRESS] -= 1;
         actualTasks[TaskStatus::IN_PROGRESS] -= 1;
         actualTasks[TaskStatus::TESTING] += 1;
      }
      else if (untouchedTasks.count(TaskStatus::TESTING) > 0 && untouchedTasks[TaskStatus::TESTING] > 0)
      {
         updatedTasks[TaskStatus::DONE] += 1;
         untouchedTasks[TaskStatus::TESTING] -= 1;
         actualTasks[TaskStatus::TESTING] -= 1;
         actualTasks[TaskStatus::DONE] += 1;
      }

      --task_count;
   }

   untouchedTasks[TaskStatus::DONE] = 0;
   RemoveZeroValue(untouchedTasks);
   RemoveZeroValue(updatedTasks);
   RemoveZeroValue(actualTasks);

   data_[person] = actualTasks;

   return std::make_tuple(updatedTasks, untouchedTasks);
}


// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void
PrintTasksInfo(TasksInfo tasks_info)
{
   cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main()
{
   TasksInfo info{
        {TaskStatus::NEW,1},
        {TaskStatus::IN_PROGRESS,4},
        {TaskStatus::TESTING,4},
        {TaskStatus::DONE,5}
    };

   TeamTasks tasks;
   tasks.data_["Ivan"] = info;

   TasksInfo updated_tasks, untouched_tasks;
   tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 17);

   PrintTasksInfo(updated_tasks);
   PrintTasksInfo(untouched_tasks);

  return 0;
}