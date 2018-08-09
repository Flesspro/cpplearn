#include <iostream>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& source) {
	vector<int> new_vector;
	for (int i = source.size()-1; i >= 0; --i) {
		new_vector.push_back(source[i]);
	}
	return (new_vector);
}

int main() {
	vector<int> source = {1, 3, 4, 10, 3};
	vector<int> res = Reversed(source);
	for (auto n : res){
		cout << n << " ";
	}

	return 0;
}
