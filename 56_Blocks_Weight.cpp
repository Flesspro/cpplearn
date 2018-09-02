#include <iostream>
#include <vector>
using namespace std;


int main() {
	int n, r;
	uint64_t sum = 0;
	cin >> n >> r;

	for (auto i = 0; i < n; i++) {
		uint64_t w, h, d;
		cin >> w >> h >> d;
		sum += w * h * d * r;
	}

	cout << sum;

	return 0;
}
