#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom (string w) {
	if (w == ""){
		return (true);
	}
	for (int i = 0; i <= w.size()-1; ++i) {
		//cout << w[i] << w[w.size()-1-i] << endl;
		if (w[i] != w[w.size()-1-i]) {
			return (false);
		}
	}
	return (true);
}

int main() {
	string w;
	cin >> w;
	//w = "";
	bool res = IsPalindrom(w);
	cout << std::boolalpha << res;

	return 0;
}
