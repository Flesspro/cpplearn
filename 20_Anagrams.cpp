#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

map<char, int> BuildCharCounters(const string& word) {
	map<char, int> dict;
	for (auto ch : word) {
		++dict[ch];
	}
	return (dict);
}

int main() {
	int n;
	cin >> n;

	string word1,  word2;
	map<char, int> dict1, dict2;

	for (int i = 1; i <= n; ++i){
		cin >> word1 >> word2;

		dict1 = BuildCharCounters(word1);
		dict2 = BuildCharCounters(word2);

		if (dict1 == dict2) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
