#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;


void AddNumber (deque<string>& base, const string& operation, const int& number)
{
	base.push_front("(");
	base.push_back(")");

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

	for (int i = 0; i < n; ++i) {
		string operation;
		int number;

		cin >> operation >> number;
		AddNumber (base, operation, number);
	}

	PrintBase (base);

	return 0;
}

