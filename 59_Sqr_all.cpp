#include <map>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

// Предварительное объявление шаблонных функций
template <typename T> T FuncA(T x);
template <typename First, typename Second> pair<First, Second> operator * (const pair <First, Second>& p1, const pair <First, Second>& p2);
template <typename Key, typename Value> map<Key, Value> operator * (const map<Key, Value>& p1, const map<Key, Value>& p2);
template <typename T> vector<T> operator * (const vector<T>& p1, const vector<T>& p2);


// Объявляем шаблонные функции
template <typename First, typename Second>
pair<First, Second> operator * (const pair <First, Second>& p1, const pair <First, Second>& p2) {
	First f = p1.first * p2.first;
	Second s = p1.second * p2.second;
	return make_pair(f, s);
}

template <typename Key, typename Value>
map<Key, Value> operator * (const map<Key, Value>& p1, const map<Key, Value>& p2) {
	map<Key, Value> res;

	for (auto c : p1) {
		if (p2.count(c.first) > 0) {
			res[c.first] = c.second * p2.at(c.first);
		} else {
			res[c.first] = c.second;
		}
	}
	return res;
}

template <typename T>
vector<T> operator * (const vector<T>& p1, const vector<T>& p2) {
	if (p1.size() != p2.size()) {
		return p1;
	}

	vector<T> res = p1;
	for (auto i = 0; i < p1.size(); i++) {
		res[i] = p1[i] * p2[i];
	}
	return res;
}

template <typename T>
T Sqr(T x) {
	T y = x * x;

	return x * x;
}

int main() {
	// Пример вызова функции
	vector<int> v = {1, 2, 3};

	cout << "vector:";

	for (int x : Sqr(v)) {
	  cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
	  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
	return 0;
}
