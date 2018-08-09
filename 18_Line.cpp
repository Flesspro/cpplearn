#include <iostream>
#include <vector>
#include <string>
using namespace std;

void worry (vector<int>& crowd, int i) {
	crowd[i] = 1;
}

void quiet (vector<int>& crowd, int i) {
	crowd[i] = 0;
}

void come (vector<int>& crowd, int k) {
	crowd.resize(crowd.size()+k);
}

int worry_count(vector<int>& crowd) {
	int sum = 0;
	for (auto p : crowd){
		sum += p;
	}
	return (sum);
}

int main() {
	vector<int> crowd;
	string command;
	int n, k;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> command;
		if (command != "WORRY_COUNT"){
			cin >> k;
		}

		if (command == "WORRY_COUNT"){
			cout << worry_count(crowd) << endl;
		} else if (command == "COME"){
			come (crowd, k);
		} else if (command == "WORRY") {
			worry(crowd, k);
		} else {
			quiet(crowd, k);
		}
	}

	return 0;
}
