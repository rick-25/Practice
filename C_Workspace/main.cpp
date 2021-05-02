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



void solve() 
{
	ll n; cin >> n;
	vector<ll> arr(n);	
	for(ll i=0; i<n; i++) 
		cin >> arr[i];

	stack<pair<ll, ll>> stk;
	stk.push({arr[0], 0});	
	
	for(ll i=1; i<n; i++) 
	{
		if(arr[i] < stk.top().first) 
			stk.push({arr[i], i});
	}

	ll ans = 0, lastIndex = n;
	while(!stk.empty()) 
	{
		ans += stk.top().first * (lastIndex - stk.top().second);
		lastIndex = stk.top().second; 
		stk.pop();
	}
	
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
    while(t--)
	solve();
	
    return 0;
}
