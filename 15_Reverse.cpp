#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector<int>& source) {
	vector<int> new_vector;
	for (int i = source.size()-1; i >= 0; --i) {
		new_vector.push_back(source[i]);
	}
	source = new_vector;
}

int main() {
	vector<int> source = {1, 3, 4, 10, 3};
	Reverse(source);
	for (auto n : source){
		cout << n << " ";
	}

	return 0;
}
