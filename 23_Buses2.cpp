#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
	int n, stop_count, ctr;
	cin >> n;

	string command;
	map<vector<string>, int> buses;
	vector<string> stops ;

	ctr = 0;


	for (int i = 1; i <= n; ++i){
		cin >> stop_count ;

		stops.resize(stop_count);

		for (string& stop : stops) {
		   cin >> stop;
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
