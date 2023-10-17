#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
  std::string s;
  is >> s;
  if (s == "BUSES_FOR_STOP") q.type = QueryType::BusesForStop;
  if (s == "STOPS_FOR_BUS") q.type = QueryType::StopsForBus;
  if (s == "ALL_BUSES") q.type = QueryType::AllBuses;
  if (s == "NEW_BUS") q.type = QueryType::NewBus;

  if (q.type == QueryType::NewBus)
  {
    is >> q.bus;
    std::size_t stop_count = 0;
    is >> stop_count;
    q.stops.resize(stop_count);
    for (std::string& stop : q.stops)
      is >> stop;
  }
  else if (q.type == QueryType::BusesForStop)
  {
    is >> q.stop;
  }
  else if (q.type == QueryType::StopsForBus)
  {
    is >> q.bus;
  }
  else if (q.type == QueryType::AllBuses)
  {

  }
  return is;
}

struct BusesForStopResponse {
   std::vector<std::string> buses_;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
   if (r.buses_.empty())
     os << "No stop";

   for (const std::string& bus : r.buses_)
   {
      os << bus << " ";
   }
   return os;
}

struct StopsForBusResponse {
   std::string bus;
   std::map<std::string, std::vector<std::string>> stops_for_bus_;
   std::map<std::string, std::vector<std::string>> buses_for_stop_;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
   if (r.stops_for_bus_.count(r.bus) == 0)
   {
      os << "No bus";
   }
   else
   {
    for (const std::string& stop : r.stops_for_bus_.at(r.bus))
    {
      os << "Stop " << stop << ": ";
      if (r.buses_for_stop_.at(stop).size() == 1)
      {
        os << "no interchange";
      }
      else
      {
        for (const std::string& other_bus : r.buses_for_stop_.at(stop))
        {
          if (r.bus != other_bus)
            os << other_bus << " ";
        }
      }
      os << std::endl;
    }
   }

   return os;
}

struct AllBusesResponse {
   std::map<std::string, std::vector<std::string>> stops_for_bus_;
   std::map<std::string, std::vector<std::string>> buses_for_stop_;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
   if (r.stops_for_bus_.empty())
    os << "No buses";
    else
    {
      for (const auto& bus_item : r.stops_for_bus_)
      {
        os << "Bus " << bus_item.first << ": ";
        for (const std::string& stop : bus_item.second)
          os << stop << " ";
        os << std::endl;
      }
    }
   return os;
}

class BusManager {
public:
   void AddBus(const string& bus, const vector<string>& stops) {
      for (const std::string& stop : stops)
      {
        stops_for_bus_[bus].push_back(stop);
        buses_for_stop_[stop].push_back(bus);
      }
   }

   BusesForStopResponse GetBusesForStop(const string& stop) const {
      BusesForStopResponse response;
      auto it = buses_for_stop_.find(stop);
      if (it != buses_for_stop_.end())
         response.buses_ = it->second;
      return response;
   }

   StopsForBusResponse GetStopsForBus(const string& bus) const {
     StopsForBusResponse response;
     response.bus = bus;
     response.buses_for_stop_ = buses_for_stop_;
     response.stops_for_bus_ = stops_for_bus_;
     return response;
   }

   AllBusesResponse GetAllBuses() const {
     AllBusesResponse response;
     response.buses_for_stop_ = buses_for_stop_;
     response.stops_for_bus_ = stops_for_bus_;
     return response;
   }

private:
   std::map<std::string, std::vector<std::string>> buses_for_stop_;
   std::map<std::string, std::vector<std::string>> stops_for_bus_;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
   int query_count;
   Query q;

   cin >> query_count;

   BusManager bm;
   for (int i = 0; i < query_count; ++i) {
     cin >> q;
     switch (q.type) {
     case QueryType::NewBus:
       bm.AddBus(q.bus, q.stops);
       break;
     case QueryType::BusesForStop:
       cout << bm.GetBusesForStop(q.stop) << endl;
       break;
     case QueryType::StopsForBus:
       cout << bm.GetStopsForBus(q.bus) << endl;
       break;
     case QueryType::AllBuses:
       cout << bm.GetAllBuses() << endl;
       break;
     }
   }

   return 0;
}