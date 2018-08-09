#include <iostream>
#include <vector>
using namespace std;

// Euclid's algorithm

int main() {
	int A;
	cin >> A;
	vector<int> v;

	while (A > 0) {
		v.push_back (A % 2);
		A /= 2;
	}

	for (int i = v.size()-1; i >=0; --i){
		cout << v[i];
	}

	return 0;
}
