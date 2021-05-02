#include <iostream>
#include <vector>
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
	ll n, ans = 0;
	cin >> n;

	for(int i=1; pow(5, i) <= n; i++)
		ans += n / pow(5, i);

	cout << ans << ln;
}


int main()  	
{

#ifndef ONLINE_JUDGE	
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
    
    ll t;
    cin >> t;
    while(t--)
	solve();
	
    return 0;
}
