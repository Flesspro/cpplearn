#include <iostream>
#include <vector>
using namespace std;


int main() {
	int n;
	int64_t sum = 0;
	cin >> n;
	vector<int64_t> temperature(n);

	for (auto& i : temperature) {
		cin >> i;
		sum += i;
	}
	int64_t avg = sum/n;

	vector<int> days;
	for (int i = 0; i < n; ++i){
		if (temperature[i]>avg) {
			days.push_back(i);
		}
	}
	cout << days.size() << endl;
	for (auto i : days){
		cout << i << " ";
	}

	return 0;
}
