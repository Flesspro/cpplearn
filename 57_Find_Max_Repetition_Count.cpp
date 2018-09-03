#include <map>
#include <vector>
#include <string>
#include <tuple>
#include <iostream>
using namespace std;

enum class Lang {
  DE, FR, IT
};

struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};

bool operator< (const Region& lhs, const Region& rhs) {
	auto lhs_key = tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) ;
	auto rhs_key = tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population) ;

	return lhs_key < rhs_key;
}

int FindMaxRepetitionCount(const vector<Region>& regions) {

	int res = 0;

	map<Region, int> ctr;

	for (const Region& reg : regions) {
		res = max(res, ++ctr[reg]);
	}

	return res;
}



// Code provided for testing:
//
//int main() {
//  cout << FindMaxRepetitionCount({
//      {
//          "Moscow",
//          "Russia",
//          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//          89
//      }, {
//          "Russia",
//          "Eurasia",
//          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//          89
//      }, {
//          "Moscow",
//          "Russia",
//          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//          89
//      }, {
//          "Moscow",
//          "Russia",
//          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//          89
//      }, {
//          "Russia",
//          "Eurasia",
//          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//          89
//      },
//  }) << endl;
//
//  cout << FindMaxRepetitionCount({
//      {
//          "Moscow",
//          "Russia",
//          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//          89
//      }, {
//          "Russia",
//          "Eurasia",
//          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//          89
//      }, {
//          "Moscow",
//          "Russia",
//          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
//          89
//      }, {
//          "Moscow",
//          "Toulouse",
//          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//          89
//      }, {
//          "Moscow",
//          "Russia",
//          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//          31
//      },
//  }) << endl;
//
//  return 0;
//}

