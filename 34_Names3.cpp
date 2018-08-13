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
  Person (const string& fname, const string& lname, const int& year) {
	  FirstName[year] = fname;
	  LastName[year] = lname;
	  birth = year;
  }
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
	  if (year >= birth) {
		  FirstName[year] = first_name;
	  }
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
	  if (year >= birth) {
		  LastName[year] = last_name;
	  }
  }
  string GetFullName(const int year) const {
    // получить имя и фамилию по состоянию на конец года year

	  if (year < birth)
		  return ("No person");

	  const vector<string> f_vec = GetNames (FirstName, year);
	  const vector<string> l_vec = GetNames (LastName, year);

	  string f_year, l_year;

	  if (f_vec.size() > 0) {
		   f_year = f_vec.back();
	  } else
		   f_year = "";

	  if (l_vec.size() > 0) {
		   l_year = l_vec.back();
	  } else
		   l_year = "";


	  if (f_year == "" && l_year == "")
		  return ("Incognito");

	  if (f_year == "")
	  		  return (l_year + " with unknown first name");

	  if (l_year == "")
	  		  return (f_year + " with unknown last name");

	  return (f_year + " " + l_year);
  }

  string GetFullNameWithHistory(const int& year) const {
    // получить все имена и фамилии по состоянию на конец года year
	  if (year < birth)
	  		  return ("No person");

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
  int birth;
};


//int main() {
//  Person person("Polina", "Sergeeva", 1960);
//  for (int year : {1959, 1960}) {
//    cout << person.GetFullNameWithHistory(year) << endl;
//  }
//
//  person.ChangeFirstName(1965, "Appolinaria");
//  person.ChangeLastName(1967, "Ivanova");
//  for (int year : {1965, 1967}) {
//    cout << person.GetFullNameWithHistory(year) << endl;
//  }
//
//  return 0;
//}
