#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
    // добавить строку s в набор
	  AllStr.push_back(s);
  }
  vector<string> GetSortedStrings() {
    // получить набор из всех добавленных строк в отсортированном порядке
	  vector<string> res = AllStr;
	  sort(begin(res), end(res));
	  return (res);
  }

private:
  // приватные поля
  vector<string> AllStr;
};

//void PrintSortedStrings(SortedStrings& strings) {
//  for (const string& s : strings.GetSortedStrings()) {
//    cout << s << " ";
//  }
//  cout << endl;
//}

int main() {
//  SortedStrings strings;
//
//  strings.AddString("first");
//  strings.AddString("third");
//  strings.AddString("second");
//  PrintSortedStrings(strings);
//
//  strings.AddString("second");
//  PrintSortedStrings(strings);

  return 0;
}
