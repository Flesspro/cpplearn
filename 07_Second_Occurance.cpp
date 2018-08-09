#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	int i = -2;
	int j = 0;

	for (auto ch : str) {
		if (ch == 'f') {
			++i;
		}

		if (i == 0) {
			cout << j;
			return 0;
		}

		++j;
	}

	cout << i;

	return 0;
}
