#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
	int Q;
	string command, word1, word2;
	map<string, set<string>> synonyms;

	cin >> Q;

	for (int i = 0; i < Q; ++i) {
		cin >> command ;

		if (command == "ADD") {
			cin >> word1 >> word2;

			synonyms[word1].insert(word2);
			synonyms[word2].insert(word1);

		} else if (command == "COUNT") {
			cin >> word1;

			cout << synonyms[word1].size() << endl;

		} else if (command == "CHECK") {
			cin >> word1 >> word2;

			if (synonyms[word1].count(word2) > 0) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}


}
