#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string.h>
#include <vector>


class Date
{
public:
   Date(int Year = 0, int Month = 0, int Day = 0)
   {
      year_ = Year;

      if (Month < 1 || Month > 12)
      {
         throw std::logic_error("Month value is invalid: " + std::to_string(Month));
      }
      month_ = Month;

      if (Day < 1 || Day > 31)
      {
         throw std::logic_error("Day value is invalid: " + std::to_string(Day));
      }
      day_ = Day;
   }

   int GetYear() const { return year_; }
   int GetMonth() const { return month_; }
   int GetDay() const { return day_; }

private:
   int year_;
   int month_;
   int day_;
};


bool operator<(const Date& lhs, const Date& rhs)
{
    return std::vector<int>{ lhs.GetYear(), lhs.GetMonth(), lhs.GetDay() } <
           std::vector<int>{ rhs.GetYear(), rhs.GetMonth(), rhs.GetDay() };
}


std::ostream& operator<<(std::ostream& Out, const Date& Date)
{
   Out << std::setfill('0') <<
            std::setw(4) << Date.GetYear() <<
            "-" << std::setw(2) << Date.GetMonth() <<
            "-" << std::setw(2) << Date.GetDay();

   return Out;
}


Date ParseDate(const std::string& StrDate)
{
   std::stringstream ss(StrDate);
   bool ok = true;

   int year;
   ok = ok && (ss >> year);
   ok = ok && (ss.peek() == '-');
   ss.ignore(1);

   int month;
   ok = ok && (ss >> month);
   ok = ok && (ss.peek() == '-');
   ss.ignore(1);

   int day;
   ok = ok && (ss >> day);
   ok = ok && (ss.eof());
   ss.ignore(1);

   if (false == ok)
   {
      throw std::invalid_argument("Wrong date format: " + StrDate);
   }

   return Date(year, month, day);
}


class Database
{
public:
   void AddEvent(const Date& Date, const std::string& Event)
   {
      db_[Date].insert(Event);
   }


   bool DeleteEvent(const Date& Date, const std::string& Event)
   {
      if (db_.count(Date) > 0 && db_.at(Date).count(Event) > 0)
      {
         db_[Date].erase(Event);
         return true;
      }

      return false;
   }


   int DeleteDate(const Date& date)
   {
      if (db_.count(date) > 0)
      {
         int eventCount = db_[date].size();
         db_.erase(date);
         return eventCount;
      }

      return 0;
   }


   std::set<std::string> Find(const Date& date) const
   {
      if (db_.count(date) > 0)
      {
         return db_.at(date);
      }

      return {};
   }


   void Print() const
   {
      for (const auto& item : db_)
      {
         for (const std::string& event : item.second)
         {
            std::cout << item.first << " " << event << std::endl;
         }
      }
   }

private:
   std::map<Date, std::set<std::string>> db_;
};


int main()
{
   try
   {
      Database db;

      std::string command;
      while (getline(std::cin, command))
      {
         std::stringstream ss(command);

         std::string operationCode;
         ss >> operationCode;

         if ("Add" == operationCode)
         {
            std::string strDate;
            std::string event;
            ss >> strDate >> event;
            Date date = ParseDate(strDate);
            db.AddEvent(date, event);
         }
         else if ("Del" == operationCode)
         {
            std::string strDate;
            ss >> strDate;
            std::string event;
            if (!ss.eof())
            {
               ss >> event;
            }

            Date date = ParseDate(strDate);

            if (event.empty())
            {
               std::cout << "Deleted " << db.DeleteDate(date) << " events" << std::endl;
            }
            else
            {
               if (db.DeleteEvent(date, event))
               {
                  std::cout << "Deleted successfully" << std::endl;
               }
               else
               {
                  std::cout << "Event not found" << std::endl;
               }
            }
         }
         else if ("Find" == operationCode)
         {
            std::string strDate;
            ss >> strDate;
            Date date = ParseDate(strDate);
            for (const std::string& event : db.Find(date))
            {
               std::cout << event << std::endl;
            }
         }
         else if ("Print" == operationCode)
         {
            db.Print();
         }
         else if (operationCode != "")
         {
            std::cout << "Unknown command: " << operationCode << std::endl;
         }
      }
   }
   catch(const std::exception& ex)
   {
      std::cout << ex.what() << std::endl;
   }

   return 0;
}