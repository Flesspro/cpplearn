#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

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

private:
  // приватные поля
  map<int, string> FirstName, LastName;
};


int main() {
//  Person person;
//
//  person.ChangeFirstName(1965, "Polina");
//  person.ChangeLastName(1967, "Sergeeva");
//  for (int year : {1900, 1965, 1990}) {
//    cout << person.GetFullName(year) << endl;
//  }
//
//  person.ChangeFirstName(1970, "Appolinaria");
//  for (int year : {1969, 1970}) {
//    cout << person.GetFullName(year) << endl;
//  }
//
//  person.ChangeLastName(1968, "Volkova");
//  for (int year : {1969, 1970}) {
//    cout << person.GetFullName(year) << endl;
//  }

  return 0;
}
