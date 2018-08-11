#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string strTolower(string& str) {
	int i = 0;
	string res = str;

	while (res[i]) {
		res[i] = tolower(res[i]);
		i++;
	}

	return (res);
}

int main() {
	int n;

	cin >> n;

	vector<string> vec(n);

	for (auto& i : vec){
		cin >> i;
	}

	sort (vec.begin(), vec.end(), [](string a, string b) {
		return (strTolower(a) < strTolower(b));
	});

	for (auto& i : vec){
		cout << i << " ";
	}

	return 0;
}
