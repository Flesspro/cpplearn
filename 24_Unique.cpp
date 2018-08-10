#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	int n;
	cin >> n;

	string word;
	set<string> words;

	for (int i = 0; i < n; ++i){
		cin >> word ;
		words.insert(word);
	}
	cout << words.size();

	return 0;
}
