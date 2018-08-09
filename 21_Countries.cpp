#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	int n, ctr;
	cin >> n;

	string command, country, new_capital, new_country;
	map<string, string> countries;

	ctr = 0;

	for (int i = 1; i <= n; ++i){
		cin >> command;

		if (command == "CHANGE_CAPITAL") {
			cin >> country >> new_capital;
			++ctr;

			if (countries[country] == "") {
				cout << "Introduce new country " << country << " with capital " << new_capital << endl ;
			} else if (countries[country] == new_capital) {
				cout << "Country " << country << " hasn't changed its capital" << endl ;
			} else {
				cout << "Country " << country << " has changed its capital from " << countries[country] << " to " << new_capital << endl ;
			}
			countries[country] = new_capital ;

		} else if (command == "RENAME") {
			cin >> country >> new_country ;
			if (country == new_country || countries[country] == "" || countries[new_country] != "") {
				cout << "Incorrect rename, skip" << endl;
				continue;
			}

			cout << "Country " << country << " with capital " << countries[country] << " has been renamed to " << new_country << endl;
			countries[new_country] = countries[country] ;
			countries[country] = "";

		} else if (command == "ABOUT") {
			cin >> country;

			if (countries[country] == "") {
				cout << "Country " << country << " doesn't exist" << endl;
				continue;
			}

			cout << "Country " << country << " has capital " << countries[country] << endl;

		} else if (command == "DUMP") {

			if (ctr == 0) {
				cout << "There are no countries in the world" << endl;
				continue;
			}

			for (auto pair : countries) {
				if (pair.second != "") {
					cout << pair.first << "/" << pair.second << " ";
				}
			}
			cout << endl;

		}
	}

	return 0;
}
