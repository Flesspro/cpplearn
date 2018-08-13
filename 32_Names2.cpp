#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> GetNames (const map<int, string>& Names, const int& year) {
	vector<string> vec;
	string prev = "";

	for (auto& name : Names) {
	  if (name.first <= year && name.second != prev) {
		  vec.push_back(name.second);
		  prev = name.second;
	  }
	}

	return vec;
}

string PrintAllNames (const vector<string>& vec) {

	if (vec.size() == 0) {
		return ("");
	}

	if (vec.size() == 1) {
		return (vec[0]);
	}

	string res = vec[vec.size()-1] + " (";

	for (int i = vec.size()-2; i > 0; --i) {
		res += vec[i] + ", ";
	}

	res += vec[0] + ")";

	return (res);
}

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
	  FirstName[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
	  LastName[year] = last_name;
  }
  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
	  int f_year = -1;
	  int l_year = -1;

	  for (auto& first_name : FirstName) {
		  if (first_name.first <= year && first_name.first > f_year) {
			  f_year = first_name.first;
		  }
	  }

	  for (auto& last_name : LastName) {
		  if (last_name.first <= year && last_name.first > l_year) {
			  l_year = last_name.first;
		  }
	  }

	  if (f_year == -1 & l_year == -1)
		  return ("Incognito");

	  if (f_year == -1)
	  		  return (LastName[l_year] + " with unknown first name");

	  if (l_year == -1)
	  		  return (FirstName[f_year] + " with unknown last name");

	  return (FirstName[f_year] + " " + LastName[l_year]);
  }

  string GetFullNameWithHistory(int year) {
    // получить все имена и фамилии по состоянию на конец года year

	  vector<string> f_vec = GetNames (FirstName, year);
	  vector<string> l_vec = GetNames (LastName, year);

	  string f_names = PrintAllNames(f_vec);
	  string l_names = PrintAllNames(l_vec);

	  if (f_names == "" & l_names == "")
		  return ("Incognito");

	  if (f_names == "")
			  return (l_names + " with unknown first name");

	  if (l_names == "")
			  return (f_names + " with unknown last name");

	  return (f_names + " " + l_names);

  }


private:
  // приватные поля
  map<int, string> FirstName, LastName;
};


//int main() {
//  Person person;
//
//  person.ChangeFirstName(1965, "Polina");
//  person.ChangeLastName(1967, "Sergeeva");
//  for (int year : {1900, 1965, 1990}) {
//    cout << person.GetFullNameWithHistory(year) << endl;
//  }
//
//  person.ChangeFirstName(1970, "Appolinaria");
//  for (int year : {1969, 1970}) {
//    cout << person.GetFullNameWithHistory(year) << endl;
//  }
//
//  person.ChangeLastName(1968, "Volkova");
//  for (int year : {1969, 1970}) {
//    cout << person.GetFullNameWithHistory(year) << endl;
//  }
//
//  person.ChangeFirstName(1990, "Polina");
//  person.ChangeLastName(1990, "Volkova-Sergeeva");
//  cout << person.GetFullNameWithHistory(1990) << endl;
//
//  person.ChangeFirstName(1966, "Pauline");
//  cout << person.GetFullNameWithHistory(1966) << endl;
//
//  person.ChangeLastName(1960, "Sergeeva");
//  for (int year : {1960, 1967}) {
//    cout << person.GetFullNameWithHistory(year) << endl;
//  }
//
//  person.ChangeLastName(1961, "Ivanova");
//  cout << person.GetFullNameWithHistory(1967) << endl;
//
//  return 0;
//}
