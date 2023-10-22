#ifndef __TEST_RUNNER_H__
#define __TEST_RUNNER_H__

#include <iostream>
#include <map>
#include <string>
#include <vector>

///////////////////////////////////////////////////////////////////////////////
///                       Шаблонный вывод контейнеров                       ///
///////////////////////////////////////////////////////////////////////////////

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

#endif // __TEST_RUNNER_H__