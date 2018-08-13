#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main (){
	ifstream input ("input.txt");
	vector<vector<int>> Table;
	int n, m;

	if (input) {
		input >> n >> m;
		input.ignore(1);

		for (int i = 0; i < n; ++i) {
			vector<int> vec ;
			string line, s;
			getline(input, line);

			stringstream ss;
			ss << line;

			for (int j = 0; j < m; ++j) {
				getline (ss, s, ',');
				vec.push_back(stoi(s));
			};

			Table.push_back(vec);
		}
	}

	for (const auto& row : Table) {
		for (int i = 0; i < m-1; ++i) {
			cout << setw(10) << row[i] << " ";
		}
		cout << setw(10) << row[m-1] << endl;
	}


	return 0;
}
