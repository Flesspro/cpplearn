#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<int> days_in_months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	string command;
	int n, k, month, last_month;

	cin >> n;

	month = 0; // начинаем с января
	vector<vector<string>> todos(days_in_months[month]);


	for (int i = 1; i <= n; ++i) {
		cin >> command;
		//cout << i << ": " << command << endl;
		if (command == "ADD"){
			cin >> k >> command;
			todos[k-1].push_back(command);
		} else if (command == "NEXT"){
			last_month = month;
			month = (month + 1) % 12;
			if (days_in_months[last_month] > days_in_months[month]) {
				for (int j = days_in_months[month] ; j < days_in_months[last_month]; ++j){
					todos[days_in_months[month]-1].insert(end(todos[days_in_months[month]-1]), begin(todos[j]), end(todos[j]));
				}
			}
			todos.resize(days_in_months[month]);
		} else {
			//if (command == "DUMP") {
			cin >> k;
			cout << todos[k-1].size() << " ";
			for (auto task : todos[k-1]) {
				cout << task << " ";
			}
			cout << endl;
		}
	}

	return 0;
}
