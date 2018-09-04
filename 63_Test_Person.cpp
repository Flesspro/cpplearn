#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

//class Person {
//public:
//  void ChangeFirstName(int year, const string& first_name) {
//    // добавить факт изменения имени на first_name в год year
//	  FirstName[year] = first_name;
//  }
//  void ChangeLastName(int year, const string& last_name) {
//    // добавить факт изменения фамилии на last_name в год year
//	  LastName[year] = last_name;
//  }
//  string GetFullName(int year) {
//    // получить имя и фамилию по состоянию на конец года year
//	  int f_year = -1;
//	  int l_year = -1;
//
//	  for (auto& first_name : FirstName) {
//		  if (first_name.first <= year && first_name.first > f_year) {
//			  f_year = first_name.first;
//		  }
//	  }
//
//	  for (auto& last_name : LastName) {
//		  if (last_name.first <= year && last_name.first > l_year) {
//			  l_year = last_name.first;
//		  }
//	  }
//
//	  if (f_year == -1 & l_year == -1)
//		  return ("Incognito");
//
//	  if (f_year == -1)
//	  		  return (LastName[l_year] + " with unknown first name");
//
//	  if (l_year == -1)
//	  		  return (FirstName[f_year] + " with unknown last name");
//
//	  return (FirstName[f_year] + " " + LastName[l_year]);
//  }
//
//private:
//  // приватные поля
//  map<int, string> FirstName, LastName;
//};

void TestIncognito () {
	Person person;
	AssertEqual (person.GetFullName(1564), "Incognito");
	AssertEqual (person.GetFullName(1564), "Incognito");

	person.ChangeLastName(1700, "Doe");
	person.ChangeFirstName(1703, "John");

	AssertEqual (person.GetFullName(1564), "Incognito");
}

void TestUnknownFirstName () {
	Person person;
	person.ChangeLastName(1700, "Doe");
	AssertEqual (person.GetFullName(1701), "Doe with unknown first name");
	AssertEqual (person.GetFullName(1800), "Doe with unknown first name");

	person.ChangeFirstName(1703, "John");
	AssertEqual (person.GetFullName(1701), "Doe with unknown first name");
	AssertEqual (person.GetFullName(1799), "John Doe");

	person.ChangeLastName(1702, "X");
	AssertEqual (person.GetFullName(1702), "X with unknown first name");

	person.ChangeLastName(1650, "Y");
	AssertEqual (person.GetFullName(1690), "Y with unknown first name");
}

void TestUnknownLastName () {
	Person person;
	person.ChangeFirstName(1700, "John");
	AssertEqual (person.GetFullName(1701), "John with unknown last name");
	AssertEqual (person.GetFullName(1800), "John with unknown last name");

	person.ChangeFirstName(1650, "Ivan");
	AssertEqual (person.GetFullName(1701), "John with unknown last name");
	AssertEqual (person.GetFullName(1690), "Ivan with unknown last name");
	AssertEqual (person.GetFullName(1690), "Ivan with unknown last name");
}

void TestFullName () {
	Person person;
	person.ChangeFirstName(1700, "John");
	AssertEqual (person.GetFullName(1701), "John with unknown last name");

	person.ChangeLastName(1703, "Doe");
	AssertEqual (person.GetFullName(1701), "John with unknown last name");
	AssertEqual (person.GetFullName(1704), "John Doe");

	person.ChangeLastName (1701, "X");
	AssertEqual (person.GetFullName(1702), "John X");
	AssertEqual (person.GetFullName(1703), "John Doe");
}


int main() {
  TestRunner runner;
  runner.RunTest (TestIncognito, "TestIncognito");
  runner.RunTest (TestUnknownFirstName, "TestUnknownFirstName");
  runner.RunTest (TestUnknownLastName, "TestUnknownLastName");
  runner.RunTest (TestFullName, "TestFullName");


  // добавьте сюда свои тесты
  return 0;
}
