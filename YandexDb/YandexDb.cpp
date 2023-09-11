#include <iostream>
#include <iomanip>
#include <map>
#include <set>

class Date
{
public:
   Date(int Year = 0, int Month = 0, int Day = 0) : year_(Year), month_(Month), day_(Day) {}

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
   if (lhs.GetYear() < rhs.GetYear())
   {
      return true;
   }
   else if (lhs.GetYear() > rhs.GetYear())
   {
      return false;
   }
   else
   {
      if (lhs.GetMonth() < rhs.GetMonth())
      {
         return true;
      }
      else if (lhs.GetMonth() > rhs.GetMonth())
      {
         return false;
      }
      else
      {
         if (lhs.GetDay() < rhs.GetDay())
         {
            return true;
         }
         else
         {
            return false;
         }
      }
   }
}


std::ostream& operator<<(std::ostream& Out, const Date& Date)
{
   Out << std::setfill('0') <<
            std::setw(4) << Date.GetYear() <<
            "-" << std::setw(2) << Date.GetMonth() <<
            "-" << std::setw(2) << Date.GetDay();

   return Out;
}

Date ParseDateFromString(std::string StrDate)
{
   std::stringstream ss(StrDate);

   int year;
   int month;
   int day;
   char separator;

   ss >> year;

   ss >> separator;
   if (!ss || separator != '-')
   {
      throw std::invalid_argument("Wrong date format: " + StrDate);
   }
   ss >> month;
   if (!ss)
   {
      throw std::invalid_argument("Wrong date format: " + StrDate);
   }
   ss >> separator;
      if (!ss || separator != '-')
   {
      throw std::invalid_argument("Wrong date format: " + StrDate);
   }
   ss >> day;
   if (!ss)
   {
      throw std::invalid_argument("Wrong date format: " + StrDate);
   }
   if (ss.peek() != EOF)
   {
      throw std::invalid_argument("Wrong date format: " + StrDate);
   }

   if (month < 1 || month > 12)
   {
      throw std::invalid_argument("Month value is invalid: " + std::to_string(month));
   }

   if (day < 1 || day > 31)
   {
      throw std::invalid_argument("Day value is invalid: " + std::to_string(day));
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
      else
      {
         return false;
      }

      return false;
   }


   int DeleteDate(const Date& date)
   {
      if (db_.count(date) > 0)
      {
         int r = db_[date].size();
         db_.erase(date);
         return r;
      }

      return 0;
   }


   bool Find(const Date& date) const
   {
      if (db_.count(date) > 0 && db_.at(date).size() > 0)
      {
         for (auto& event : db_.at(date))
         {
            std::cout << event << std::endl;
         }
         return true;
      }

      return false;
   }


   void Print() const
   {
      for (const auto& item : db_)
      {
         if (item.second.size() > 0)
         {
            for (const std::string& event : item.second)
            {
               std::cout << item.first << " " << event << std::endl;
            }
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
            Date date = ParseDateFromString(strDate);
            db.AddEvent(date, event);
         }
         else if ("Del" == operationCode)
         {
            std::string strDate;
            std::string event;
            ss >> strDate >> event;
            Date date = ParseDateFromString(strDate);

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
            Date date = ParseDateFromString(strDate);
            db.Find(date);
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