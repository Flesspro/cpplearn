#include <iostream>
#include <string>
#include <vector>
using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
	for (auto w : source) {
		destination.push_back(w);
	}
	source.clear();
}

int main() {
	vector<string> source = {"1", "hey", "jude"};
	vector<string> destination = {"dont", "be", "afraid"};
	MoveStrings(source, destination);
	cout << "destination = " << endl;
	for (auto w : destination){
		cout << w << " ";
	}
	cout << endl << "source = " << endl;
	for (auto w : source){
		cout << w << " ";
	}

	return 0;
}
