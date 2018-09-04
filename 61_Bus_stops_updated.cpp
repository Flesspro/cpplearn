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
	// Реализуйте эту функцию
	string command, stop_i;
	is >> command;
	int ctr;
	q.stops = {};

	if (command == "NEW_BUS") {
		q.type = QueryType::NewBus;
		is >> q.bus >> ctr;
		for (int i = 0; i < ctr; i++) {
			is >> stop_i;
			q.stops.push_back(stop_i);
		}
	} else if (command ==  "BUSES_FOR_STOP") {
		q.type = QueryType::BusesForStop;
		is >> q.stop;
	} else if (command == "STOPS_FOR_BUS") {
		q.type = QueryType::StopsForBus;
		is >> q.bus;
	} else if (command == "ALL_BUSES") {
		q.type = QueryType::AllBuses;
	} else
		throw runtime_error ("wrong command");

	return is;
}

struct BusesForStopResponse {
	// Наполните полями эту структуру
	string stop;
	bool exists;
	vector<string> buses;
};


// Printing vectors
ostream& operator << (ostream& os, const vector<string> v) {
	for (int i = 0; i + 1 < v.size(); i++) {
		os << v[i] << " ";
	}

	//cout << v[0];
	os << v[v.size()-1] ;

	return os;
}

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	// Реализуйте эту функцию
	if (r.exists) {
		os << r.buses;
	} else {
		os << "No stop";
	}
	return os;
}

struct StopsForBusResponse {
	// Наполните полями эту структуру
	string bus;
	bool exists;
	vector<string> stop_names;
	map<string, vector<string>> stop_to_buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	// Реализуйте эту функцию
	if (r.exists) {
		int ctr = 0;

		for (auto stop : r.stop_names) {
			++ctr;

			os << "Stop " << stop << ": " ;
			if (r.stop_to_buses.at(stop).size() == 1) {
				os << "no interchange";
			} else {
				for (auto bus : r.stop_to_buses.at(stop)) {
					if (bus != r.bus) {
						os << bus << " ";
					}
				}
			}
			if (ctr < r.stop_names.size() ) {
				os << endl;
			}
		}
	} else {
		os << "No bus";
	}

	return os;
}

struct AllBusesResponse {
	// Наполните полями эту структуру
	bool exists;
	vector<StopsForBusResponse> buses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	// Реализуйте эту функцию
	if (r.exists) {
		for (auto bus : r.buses) {
			os << "Bus " << bus.bus << ": " << bus.stop_names << endl;
		}
	} else {
		os << "No buses";
	}
	return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops_list) {
	  // Реализуйте этот метод

	  //cout << bus << stops_list << endl ;
	  for (auto i : stops_list) {
		  buses[bus].push_back(i);
		  stops[i].push_back(bus);
	  }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
	  // Реализуйте этот метод
	  BusesForStopResponse res;
	  res.stop = stop;
	  if (stops.count(stop) == 0) {
		  res.exists = false;
		  return res;
	  } else {
		  res.exists = true;
		  res.buses = {};
		  for (auto i : stops.at(stop)) {
			  res.buses.push_back(i);
		  }
	  }

	  return res;
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
	  // Реализуйте этот метод
	  StopsForBusResponse res;
	  res.bus = bus;
	  if (buses.count(bus) == 0) {
		  res.exists = false;
		  return res;
	  } else {
		  res.exists = true;
		  res.stop_names = buses.at(bus);
		  for (string stop : res.stop_names) {
			  res.stop_to_buses[stop] = stops.at(stop);
		  }
	  }

	  return res;
  }

  AllBusesResponse GetAllBuses() const {
    // Реализуйте этот метод
	  AllBusesResponse res;
	  if (buses.empty()) {
		  res.exists = false;
		  return res;
	  } else {
		  res.exists = true;
		  for (auto bus : buses) {
			  res.buses.push_back(GetStopsForBus(bus.first));
		  }
	  }
	  return res;
  }

private:
  map<string, vector<string>> buses;
  map<string, vector<string>> stops;
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
