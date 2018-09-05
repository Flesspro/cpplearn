#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s)
{
	vector<string> res;

	auto iter1 = begin(s);
	auto iter2 = begin(s);

	while (iter1 < end(s)) {
		iter2 = find_if(iter1, end(s),
				[](const char& ch) {
					return ch == ' ';
				});
		res.push_back(string(iter1, iter2));
		//cout << (string(iter1, iter2)) << endl;

		iter1 = iter2+1;
	}

	return res;
}

int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;

  return 0;
}
