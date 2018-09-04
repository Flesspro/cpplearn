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


int GetDistinctRealRootCount(double a, double b, double c) {
  // Вы можете вставлять сюда различные реализации функции,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
	if (a == 0) {
		if (b == 0 && c != 0) {
			return 0;
		} else return 1;
	}

	double d = b * b - 4 * a * c;

	if (d > 0) {
		return 2;
	} else if (d == 0) {
		return 1;
	} else return 0;
}

void TestAB () {
	AssertEqual(GetDistinctRealRootCount(0, 0, 13), 0);
	AssertEqual(GetDistinctRealRootCount(0, 0, -13), 0);
}

void TestAC () {
	AssertEqual(GetDistinctRealRootCount(0, 13, 0), 1);
	AssertEqual(GetDistinctRealRootCount(0, -13, 0), 1);
}

void TestBC () {
	AssertEqual(GetDistinctRealRootCount(-13, 0, 0), 1);
	AssertEqual(GetDistinctRealRootCount(13, 0, 0), 1);
}

void TestA () {
	AssertEqual(GetDistinctRealRootCount(0, 10, 100), 1);
	AssertEqual(GetDistinctRealRootCount(0, 10, -100), 1);
	AssertEqual(GetDistinctRealRootCount(0, -10, 100), 1);
	AssertEqual(GetDistinctRealRootCount(0, -10, -100), 1);
}

void TestB () {
	AssertEqual(GetDistinctRealRootCount(10, 0, 100), 0);
	AssertEqual(GetDistinctRealRootCount(10, 0, -100), 2);
	AssertEqual(GetDistinctRealRootCount(-10, 0, -100), 0);
	AssertEqual(GetDistinctRealRootCount(-10, 0, 100), 2);
}


void TestC () {
	AssertEqual(GetDistinctRealRootCount(10, 10, 0), 2);
	AssertEqual(GetDistinctRealRootCount(10, 20, 0), 2);
	AssertEqual(GetDistinctRealRootCount(-10, 20, 0), 2);
	AssertEqual(GetDistinctRealRootCount(-10, 20, 0), 2);
}

void Test () {
	AssertEqual(GetDistinctRealRootCount(10, 20, 10), 1);
	AssertEqual(GetDistinctRealRootCount(10, 20, 20), 0);
	AssertEqual(GetDistinctRealRootCount(10, 20, -10), 2);
	AssertEqual(GetDistinctRealRootCount(10, 10, 10), 0);
}

void TestDouble () {
	AssertEqual(GetDistinctRealRootCount(0.2, 0.4, 0.2), 1);
	AssertEqual(GetDistinctRealRootCount(-0.2, -0.4, -0.2), 1);
	AssertEqual(GetDistinctRealRootCount(0.2, -0.4, 0), 2);
	AssertEqual(GetDistinctRealRootCount(0.2, 0, 0.2), 0);
}

int main() {
  TestRunner runner;
  runner.RunTest (TestAB, "TestAB");
  runner.RunTest (TestBC, "TestBC");
  runner.RunTest (TestAC, "TestAC");
  runner.RunTest (TestA, "TestA");
  runner.RunTest (TestB, "TestB");
  runner.RunTest (TestC, "TestC");
  runner.RunTest (Test, "Test");
  runner.RunTest (TestDouble, "TestDouble");


  // добавьте сюда свои тесты
  return 0;
}
