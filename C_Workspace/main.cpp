#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define ln '\n'
#define ll long long	

ll ans;


ll help(string s, int root) 
{
	for(int i=root+1; i<s.size(); /*i++*/)	
	{
		if(s[i] == '>') 
		{
			ans = max(ans, (ll)(i - root)+1);
			return i;
		}
		else 
		{
			ll nextIndex = help(s, i);
			if(nextIndex < 0 || nextIndex >= s.size()) 
				return nextIndex;

			i = nextIndex+1;
		}
	}
	return -1;
}



void solve()
{
	string s;
	cin >> s;

	if(s[0] == '>') {
		cout << 0 << ln;
		return;
	}

	ans = 0;
	help(s, 0);
	cout << ans << ln;
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
