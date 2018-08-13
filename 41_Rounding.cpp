#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main (){
	ifstream input ("input.txt");
	double v = 0;
	string line;

	cout << fixed << setprecision(3);
	while (input >> v) {
		cout << v << endl;
	}
	return 0;
}
