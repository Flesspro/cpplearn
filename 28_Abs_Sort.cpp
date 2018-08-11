#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;

	cin >> n;

	vector<int> vec(n);

	for (auto& i : vec){
		cin >> i;
	}

	sort (vec.begin(), vec.end(), [](int a, int b) {
		return (abs(a) < abs(b));
	});

	for (auto& i : vec){
		cout << i << " ";
	}

	return 0;
}
