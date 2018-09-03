#include <map>
#include <vector>
#include <string>
#include <utility>
#include <iostream>
using namespace std;

template <typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& mp, const Key& k) {
	if (mp.count(k) == 0) {
		throw runtime_error("wrong key") ;
	}

	return mp.at(k);
}

int main() {

	map<int, string> m = {{0, "value"}};
	string& item = GetRefStrict(m, 0);
	item = "newvalue";
	cout << m[0] << endl; // выведет newvalue

	return 0;
}
