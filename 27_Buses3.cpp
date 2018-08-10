#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {
	int n, stop_count, ctr;
	cin >> n;

	string command;
	map<set<string>, int> buses;
	set<string> stops ;
	string stop;

	ctr = 0;

	for (int i = 0; i < n; ++i){
		cin >> stop_count ;

		stops.clear();

		for (int j = 0; j < stop_count; ++j) {
		   cin >> stop;
		   stops.insert(stop);
		}

		if (buses.count(stops) == 0) {
			++ctr;
			buses[stops] = ctr;
			cout << "New bus " << ctr << endl;
		} else {
			cout << "Already exists for "  << buses[stops] << endl;
		}
	}

	return 0;
}
