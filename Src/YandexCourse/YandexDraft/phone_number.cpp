#include <algorithm>
#include <exception>
#include <iostream>
#include <stdexcept>

#include "phone_number.h"

PhoneNumber::PhoneNumber(const std::string& international_number)
{
   if (international_number.front() != '+')
   {
      throw std::invalid_argument("Invalid format");
   }

   auto itCountryCodeBegin = international_number.begin() + 1;
   if (itCountryCodeBegin == international_number.end())
   {
      throw std::invalid_argument("Invalid format");
   }
   auto itCountryCodeEnd = std::find(international_number.begin(), international_number.end(), '-');
   if (itCountryCodeEnd == international_number.end() || itCountryCodeEnd - itCountryCodeBegin == 0)
   {
      throw std::invalid_argument("Invalid format");
   }
   country_code_ = std::string{itCountryCodeBegin, itCountryCodeEnd};

   auto itCityCodeBegin = itCountryCodeEnd + 1;
   if (itCityCodeBegin == international_number.end())
   {
      throw std::invalid_argument("Invalid format");
   }
   auto itCityCodeEnd = std::find(itCityCodeBegin, international_number.end(), '-');
   if (itCityCodeEnd == international_number.end() || itCityCodeEnd - itCityCodeBegin == 0)
   {
      throw std::invalid_argument("Invalid format");
   }
   city_code_ = std::string{itCityCodeBegin, itCityCodeEnd};

   auto itLocalNumber = itCityCodeEnd + 1;
   if (itLocalNumber == international_number.end())
   {
      throw std::invalid_argument("Invalid format");
   }
   local_number_ = std::string{itLocalNumber, international_number.end()};
}


string PhoneNumber::GetCountryCode() const
{
   return country_code_;
}

string PhoneNumber::GetCityCode() const
{
   return city_code_;
}

string PhoneNumber::GetLocalNumber() const
{
   return local_number_;
}

string PhoneNumber::GetInternationalNumber() const
{
   return {"+" + country_code_ + "-" + city_code_ + "-" + local_number_};
}


// int main()
// {
//    try
//    {
//       PhoneNumber number{"+7-1233"};
//       std::cout << number.GetCountryCode() << std::endl;
//       std::cout << number.GetCityCode() << std::endl;
//       std::cout << number.GetLocalNumber() << std::endl;
//       std::cout << number.GetInternationalNumber() << std::endl;
//    }
//    catch (const std::exception& ex)
//    {
//       std::cout << ex.what() << std::endl;
//    }

//    return 0;
// }