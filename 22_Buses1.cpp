#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
	int n, stop_count;
	cin >> n;

	string command, bus, stop;
	map<string, vector<string>> buses, stops;


	for (int i = 1; i <= n; ++i){
		cin >> command;

		if (command == "NEW_BUS") {
			cin >> bus >> stop_count ;
			for (int j = 1; j <= stop_count; ++j) {
				cin >> stop;
				buses[bus].push_back(stop);
				stops[stop].push_back(bus);
			}


		} else if (command == "STOPS_FOR_BUS") {
			cin >> bus;
			if (buses.count(bus) == 0) {
				cout << "No bus" << endl;
			} else {
				for (auto s : buses[bus]) {
					cout << "Stop " << s << ": ";

					if (stops[s].size() == 1) {
						cout << "no interchange" << endl;
					} else {
						for (auto b : stops[s]) {
							if (b != bus) {
								cout << b << " ";
							}
						}

						cout << endl;
					}
				}
			}

		} else if (command == "BUSES_FOR_STOP") {
			cin >> stop;
			if (stops.count(stop) == 0) {
				cout << "No stop";
			} else {
				for (auto b : stops[stop]) {
					cout << b << " ";
				}
			}

			cout << endl;

		} else if (command == "ALL_BUSES") {
			if (buses.empty()) {
				cout << "No buses" << endl;
			} else {
				for (auto b : buses) {
					if (b.second.size() != 0) {
						cout << "Bus " << b.first << ": ";
						for (auto s : b.second) {
							cout << s << " ";
						}
						cout << endl;
					}
				}
			}
		}
	}

	return 0;
}
