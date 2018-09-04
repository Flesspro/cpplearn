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


//int GCD (const int& a, const int& b) {
//	if (a*b == 0) {
//		return (a+b);
//	} else if (a > b) {
//		return GCD (a%b, b);
//	} else
//		return GCD (b%a, a);
//}
//
//
//class Rational {
//public:
//    Rational() {
//        // Реализуйте конструктор по умолчанию
//    	num = 0;
//    	den = 1;
//    }
//
//    Rational(int numerator, int denominator) {
//        // Реализуйте конструктор
//    	int gcd = GCD (abs(numerator), abs(denominator));
//    	num = numerator / gcd;
//    	den = denominator / gcd;
//
//    	if (num*den < 0) {
//    		num = -abs(num);
//    		den = abs(den);
//    	} else {
//    		num = abs(num);
//    	    den = abs(den);
//    	}
//
//    }
//
//    int Numerator() const {
//        // Реализуйте этот метод
//    	return num;
//    }
//
//    int Denominator() const {
//        // Реализуйте этот метод
//    	return den;
//    }
//
//private:
//    // Добавьте поля
//    int num;
//    int den;
//};

void TestDefault () {
	Rational r;
	AssertEqual (r.Numerator(), 0);
	AssertEqual (r.Denominator(), 1);
}

void TestElimination () {
	Rational r1(1,2);
	AssertEqual (r1.Numerator(), 1);
	AssertEqual (r1.Denominator(), 2);

	Rational r2(512,1024);
	AssertEqual (r2.Numerator(), 1);
	AssertEqual (r2.Denominator(), 2);

	Rational r3(4,1);
	AssertEqual (r3.Numerator(), 4);
	AssertEqual (r3.Denominator(), 1);

	Rational r4(220,110);
	AssertEqual (r4.Numerator(), 2);
	AssertEqual (r4.Denominator(), 1);
}

void TestNegative () {
	Rational r1(-2, 3);
	AssertEqual (r1.Numerator(), -2);
	AssertEqual (r1.Denominator(), 3);

	Rational r2(2, -3);
	AssertEqual (r2.Numerator(), -2);
	AssertEqual (r2.Denominator(), 3);
}

void TestPositive () {
	Rational r1(-2, -3);
	AssertEqual (r1.Numerator(), 2);
	AssertEqual (r1.Denominator(), 3);
}

void TestZero () {
	Rational r1(0, 234);
	AssertEqual (r1.Numerator(), 0);
	AssertEqual (r1.Denominator(), 1);
}


int main() {
  TestRunner runner;
  runner.RunTest (TestDefault, "TestDefault") ;
  runner.RunTest (TestElimination, "TestElimination") ;
  runner.RunTest (TestNegative, "TestNegative");
  runner.RunTest (TestPositive, "TestPositive");
  runner.RunTest (TestZero, "TestZero");


  // добавьте сюда свои тесты
  return 0;
}
