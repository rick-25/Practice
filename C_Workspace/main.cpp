#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ln '\n'
typedef long long ll;


void solve()	
{
	ll n, k;
	cin >> n >> k;
    vector<ll> arr = vector<ll>(n);
	for(int i=0; i<n; i++)
		cin >> arr[i];


    ll l1 = arr[n/2] - k/2;
    ll l2 = arr[n/2 - 1] - k/2;
    

	ll ans = 1e18; 

    for(ll  l : {l1 ,l2}) 
    {
        ll r = l + k - 1;
        ll dist = 0;
        for(ll i=0; i<n; i++) 
            dist += max(abs(arr[i] - l), abs(arr[i] - r));
        ans = min(ans, dist);
    }
    
    
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
    while(t--)	solve();

    return 0;
}
