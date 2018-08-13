#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

struct Student {
	string fname ;
	string lname ;
	int bday ;
	int bmonth ;
	int byear ;
};

int main (){
	int n, m, value;
	string command;
	vector<Student> students;
	Student example;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> example.fname;
		cin.ignore();
		cin >> example.lname;
		cin.ignore();
		cin >> example.bday;
		cin.ignore();
		cin >> example.bmonth;
		cin.ignore();
		cin >> example.byear;

		students.push_back(example);
	}

	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> command;
		cin.ignore();
		cin >> value;

		if (command == "name" && value > 0 && value <= n) {
			cout << students[value-1].fname << " " << students[value-1].lname << endl;
		} else if (command == "date" && value > 0 && value <= n) {
			cout << students[value-1].bday << "." << students[value-1].bmonth
					<< "." << students[value-1].byear << endl;
		} else {
			cout << "bad request" << endl;
		}
	}
	return 0;
}
