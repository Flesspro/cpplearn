#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
	if (range_begin+1 == range_end) {
		return;
	}

	vector<typename RandomIt::value_type> elements(range_begin, range_end);

	auto part1 = begin(elements) + elements.size() / 3;
	auto part2 = part1 + elements.size() / 3;
	//cout << *range_begin << " " << *range_end << " " << *part1 << " " << *part2 << endl;

	MergeSort (begin(elements), part1) ;
	MergeSort (part1, part2);
	MergeSort (part2, end(elements));

	vector<typename RandomIt::value_type> temp;
	merge(begin(elements), part1, part1, part2, back_inserter(temp));
	merge(begin(temp), end(temp), part2, end(elements), range_begin);
}

int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}

