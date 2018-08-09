#include <iostream>
#include <string>
#include <vector>
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


vector<string> PalindromFilter (vector<string> words, int minLength) {
	vector<string> res ;
	for (auto s : words) {
		//cout << s << " ";
		if (IsPalindrom(s) && s.size() >= minLength) {
			res.push_back(s);
		}
	}
	return(res);
}


int main() {
	vector<string> res;
	res = PalindromFilter ({"weew", "bro", "code"}, 4);
	for (auto s: res) {
		cout << s << " ";
	}

	return 0;
}
