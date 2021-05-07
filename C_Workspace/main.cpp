#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define ln '\n'
#define ll long long



void solve()
{
	ll n, k;
	cin >> n >> k;

	vector<int> arr(n);
	for(int i=0; i<n; i++)	cin >> arr[i];

	queue<pair<int, int>> indexQueue;
	unordered_set<int> currentFlavours;

	for(int i=0; i<n; i++) 
	{
		
	}


}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	ll t = 1;
	cin >> t;
	while (t--)
		solve();

	return 0;
}
