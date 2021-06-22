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


void solve()
{
	int n, q;
	vector<int> arr(long(1e6));
	vector<int> qu(long(1e6));

	cin >> n >> q;
	for(int i=0; i<n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	for(int i=0; i<q; i++)
		cin >> qu[i];

	for(int i=0; i<q; i++)
	{
		auto it = lower_bound(arr.begin(), arr.end(), qu[i]);
		if(it != arr.end() && (*it) == qu[i])
		{
			cout << "0" << ln;
			continue;
		}

		int biger = distance(it, arr.end());
		if(biger % 2 != 0)
			cout << "NEGATIVE" << ln;
		else
			cout << "POSITIVE" << ln;
	}
}

int main()
{
	//freopen("inputf.in", "r", stdin);
	ll t = 1;
	
	//cin >> t;
	while (t--)
		solve();
	return 0;
}

