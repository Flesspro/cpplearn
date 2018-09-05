#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void PrintVectorPart(const vector<int>& numbers)
{
	auto head = find_if(begin(numbers), end(numbers),
			[](const int& num) {
				return num < 0;
			});

	while (head > begin(numbers)) {
		--head ;
		cout << *head << " ";
	}

	cout << endl;
}


int main() {
  PrintVectorPart({6, 1, 8, -5, 4});
  PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
  PrintVectorPart({6, 1, 8, 5, 4});
  return 0;
}
