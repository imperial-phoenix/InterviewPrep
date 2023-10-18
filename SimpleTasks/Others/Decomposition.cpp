#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>


enum class QueryType {
   NewBus,
   BusesForStop,
   StopsForBus,
   AllBuses
};


struct Query {
  QueryType type;
  std::string bus;
  std::string stop;
  std::vector<std::string> stops;
};


std::istream& operator >> (std::istream& is, Query& q) {
   std::string query;
   is >> query;
   if (query == "BUSES_FOR_STOP") {
      q.type = QueryType::BusesForStop;
   }
   else if (query == "STOPS_FOR_BUS") {
      q.type = QueryType::StopsForBus;
   }
   else if (query == "ALL_BUSES") {
      q.type = QueryType::AllBuses;
   }
   else if (query == "NEW_BUS") {
      q.type = QueryType::NewBus;
   }

   switch (q.type)
   {
   case QueryType::NewBus:
   {
      is >> q.bus;
      std::size_t stops_count = 0;
      is >> stops_count;
      q.stops.resize(stops_count);
      for (std::string& stop : q.stops) {
         is >> stop;
      }
      break;
   }
   case QueryType::BusesForStop:
   {
      is >> q.stop;
      break;
   }
   case QueryType::StopsForBus:
   {
      is >> q.bus;
      break;
   }
   case QueryType::AllBuses:
      break;
   }

  return is;
}


struct BusesForStopResponse {
   std::vector<std::string> buses_;
};


std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r) {
   if (r.buses_.empty()) {
     os << "No stop";
   }

   for (const std::string& bus : r.buses_) {
      os << bus << " ";
   }

   return os;
}


struct StopsForBusResponse {
   const std::string& bus;
   const std::map<std::string, std::vector<std::string>>& stops_for_bus_;
   const std::map<std::string, std::vector<std::string>>& buses_for_stop_;
};


std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r) {
   if (r.stops_for_bus_.count(r.bus) == 0)
   {
      os << "No bus";
   }
   else
   {
      bool isFirst = true;

      for (const std::string& stop : r.stops_for_bus_.at(r.bus)) {
         if (false == isFirst) {
            os << std::endl;
         }

         os << "Stop " << stop << ": ";
         if (r.buses_for_stop_.at(stop).size() == 1) {
            os << "no interchange";
         }
         else {
            for (const std::string& other_bus : r.buses_for_stop_.at(stop)) {
               if (r.bus != other_bus)
               os << other_bus << " ";
            }
         }

         isFirst = false;
      }
   }

   return os;
}


struct AllBusesResponse {
   const std::map<std::string, std::vector<std::string>>& stops_for_bus_;
   const std::map<std::string, std::vector<std::string>>& buses_for_stop_;
};


std::ostream& operator << (std::ostream& os, const AllBusesResponse& r) {
   if (r.stops_for_bus_.empty())
      os << "No buses";
   else
   {
      bool isFirst = true;
      for (const auto& bus_item : r.stops_for_bus_)
      {
         if (false == isFirst) {
            os << std::endl;
         }

         os << "Bus " << bus_item.first << ": ";
         for (const std::string& stop : bus_item.second) {
            os << stop << " ";
         }

         isFirst = false;
      }
   }
   return os;
}


class BusManager {
public:
   void AddBus(const std::string& bus, const std::vector<std::string>& stops) {
      for (const std::string& stop : stops)
      {
        stops_for_bus_[bus].push_back(stop);
        buses_for_stop_[stop].push_back(bus);
      }
   }

   BusesForStopResponse GetBusesForStop(const std::string& stop) const {
      BusesForStopResponse response;
      auto it = buses_for_stop_.find(stop);
      if (it != buses_for_stop_.end())
         response.buses_ = it->second;
      return response;
   }

   StopsForBusResponse GetStopsForBus(const std::string& bus) const {
      StopsForBusResponse response { bus, stops_for_bus_, buses_for_stop_ };
      return response;
   }

   AllBusesResponse GetAllBuses() const {
      AllBusesResponse response { stops_for_bus_, buses_for_stop_ };
      return response;
   }

private:
   std::map<std::string, std::vector<std::string>> buses_for_stop_;
   std::map<std::string, std::vector<std::string>> stops_for_bus_;
};


// Не меняя тела функции main, реализуйте функции и классы выше
int main() {
   int query_count;
   std::cin >> query_count;

   BusManager bm;
   for (int i = 0; i < query_count; ++i) {
      Query q;
      std::cin >> q;

      switch (q.type) {
      case QueryType::NewBus:
         bm.AddBus(q.bus, q.stops);
         break;
      case QueryType::BusesForStop:
         std::cout << bm.GetBusesForStop(q.stop) << std::endl;
         break;
     case QueryType::StopsForBus:
         std::cout << bm.GetStopsForBus(q.bus) << std::endl;
         break;
     case QueryType::AllBuses:
         std::cout << bm.GetAllBuses() << std::endl;
         break;
      }
   }

   return 0;
}