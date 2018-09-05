#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

set<int>::const_iterator FindNearestElement(
    const set<int>& numbers,
    int border)
{
	auto lwr = numbers.lower_bound(border);

	if (lwr == begin(numbers))
	{
		return lwr;
	} else if (lwr == end(numbers))
	{
		return prev(lwr);
	} else if (abs(*lwr - border) < abs(*prev(lwr) - border))
	{
		return lwr;
	} else return prev(lwr);
}
// set<int>::const_iterator —
// тип итераторов для константного множества целых чисел

int main() {
  set<int> numbers = {1, 4, 6};
  cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;

  set<int> empty_set;

  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}

