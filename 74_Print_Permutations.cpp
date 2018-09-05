#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;
int ans[10], used[10], n;
void dfs(int lvl)
{
	if (lvl == n)
	{
		for (int i = 0; i < n; i++)
			cout << ans[i] << " ";
		cout << endl;
	}

	for (int i = n; i >= 1; i--)
		if (used[i] == 0)
		{
			used[i] = 1;
			ans[lvl] = i;
			dfs(lvl+1);
			used[i] = 0;
		}
}
int main()
{
	cin >> n;
	dfs(0);
	return 0;
}
