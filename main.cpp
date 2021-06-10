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
	ll n, m;
	cin >> n >> m;

	vector<ll> cities(n);
	vector<ll> travellers(m);

	for(int i=0; i<n; i++)
		cin >> cities[i];
	for(int i=0; i<m; i++)
		cin >> travellers[i];

	vector<ll> left(n);
	vector<ll> right(n);

	ll last = n;
	for(int i=n-1; i>-1; i--)
	{
		if(cities[i] == 2)
			last = i;
		
		left[i] = -1;
		if(last < n)	left[i] = last-i;
	}

	last = -1;
	for(int i=0; i<n; i++)
	{
		if(cities[i] == 1)
			last = i;

		right[i] = -1;
		if(last > -1)	right[i] = i-last;
	}

	for(int i=0; i<m; i++)
	{
		int index = travellers[i]-1; 

		int ans = -1;
		
		if(left[index] != -1)
			ans = left[index];

		if(right[index] != -1) {
			if(left[index] != -1)
				ans = min((ll)left[index], (ll)right[index]);
			else 
				ans = right[index];
		}

		cout << ans << ' ';
	}
	cout << ln;
}

int main()
{
	freopen("inputf.in", "r", stdin);
	ll t = 1;
	
	cin >> t;
	while (t--)
        solve();

	return 0;
}

