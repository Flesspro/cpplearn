#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


string FindName(const map<int, string>& names, int year)
{
	auto iterator = names.upper_bound(year);
	string name;

	if (iterator != names.begin()) {
		name = prev(iterator) -> second;
	}
	return name;
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
	  string fname = FindName (FirstName, year);
	  string lname = FindName (LastName, year);

	  if (fname.empty() && lname.empty())
		  return ("Incognito");

	  if (fname.empty())
	  		  return (lname + " with unknown first name");

	  if (lname.empty())
	  		  return (fname + " with unknown last name");

	  return (fname + " " + lname);
  }

private:
  // приватные поля
  map<int, string> FirstName, LastName;
};


int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  return 0;
}

