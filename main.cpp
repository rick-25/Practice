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


int gcd(int a, int b) 
{
	if(a == 0 || b == 0)
		return max(a, b);
	
	if(a == b)
		return a;
	else if(a > b)
		a %= b;
	else
		b %= a;

	return gcd(a, b);
}


void solve()
{
	unordered_map<int, int> mp;
	for(int i=0; i<4; i++)
	{
		int temp; cin >> temp;
		mp[temp]++;
	}

	int ans;
	if(mp.size() == 4 || mp.size() == 3)
		ans = 2;
	else if(mp.size() == 2) {
		if(mp.begin()->second == 2)
			ans = 2;
		else
			ans = 1;
	} else 
		ans = 0;

	cout << ans << ln;
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

