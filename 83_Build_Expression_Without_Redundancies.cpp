#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;


void AddNumber (deque<string>& base, const string& operation, const int& number, const bool& priority)
{
	if (priority) {
		base.push_front("(");
		base.push_back(")");
	}

	string s = " " + operation + " " + to_string(number);

	base.push_back(s);
}

void PrintBase (deque<string>& base)
{
	for (int i = 0; i < base.size(); ++i) {
		cout << base[i];
	}
}

int main()
{
	int start, n;
	cin >> start >> n;

	deque<string> base;
	base.push_back(to_string(start));

	bool previous_high_priority = true;
	bool current_high_priority = false;
	bool priority_change = false;

	for (int i = 0; i < n; ++i) {
		string operation;
		int number;

		cin >> operation >> number;

		if (operation == "*" || operation == "/") {
			current_high_priority = true;
		} else {
			current_high_priority = false;
		}

		if (previous_high_priority == false && current_high_priority == true) {
			priority_change = true;
		} else {
			priority_change = false;
		}

		AddNumber (base, operation, number, priority_change);

		previous_high_priority = current_high_priority;
	}

	PrintBase (base);

	return 0;
}

