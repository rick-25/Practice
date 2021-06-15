#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <iterator>
#include <algorithm>
#include <climits>
#include <cmath>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define ln '\n'
#define ll long long
#define MOD 1000000007

vector<int> list[int(1e5)];

void dfs(int root, unordered_set<int>& visited)
{
	if(visited.find(root) != visited.end())	return;
	visited.insert(root);

	for(int i=0; i<list[root].size(); i++)
		dfs(list[root][i], visited);
}
void solve()
{
	int e;
	cin >> e;

	int maxNode = 1;

	for(int i=0; i<e; i++)
	{
		int x, y;	cin >> x >> y;
		list[x].push_back(y);
		list[y].push_back(x);

		maxNode = max(maxNode, max(x, y));
	}
	
	unordered_set<int> seen;
	for(int i=1; i<=maxNode; i++)
	{
		if(list[i].size() > 0)
			dfs(i, seen);
	}

	cout << seen.size() << '\n';
}

int main()
{
	//freopen("inputf.in", "r", stdin);
	ll t = 1;
	
	cin >> t;
	while (t--)
        solve();

	return 0;
}

