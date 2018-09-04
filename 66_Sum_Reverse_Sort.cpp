#include <string>
#include <vector>
#include <algorithm>

#include "sum_reverse_sort.h"

using namespace std;

int Sum(int x, int y)
{
	return x + y;
}

string Reverse(string s)
{
	string res = "";

	if (s.size() > 0) {
		for (int i = s.size()-1; i >= 0; i--) {
			res += s[i];
		}
	}

	return res;
}

void flip(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void Sort(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
}
