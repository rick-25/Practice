#include <bits/stdc++.h>

using namespace std;

#define ln '\n'
#define sp ' '
#define ll long long
#define MOD 1000000007

const int MAX_N = 1e5 + 5;




//int dp[MAX_N];
//int arr[MAX_N];



void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> arr(n);
    for(auto& i : arr) cin >> i;
    sort(arr.begin(), arr.end(), greater<ll>());
    
    ll ans = arr[0] + arr[0];  
    for(int i=1; i<n; i++) {
        if(arr[i] == arr[0]) continue;
        ll temp = (arr[0] - arr[i]) % m;
        cout << (arr[i] - arr[0]) % m << ln;
        ans = max(ans, arr[i] + arr[0] + temp);
    }

    cout << ans;
}


int main(const int argLen, const char ** args) {
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#ifndef ONLINE_JUDGE
    cout << ln; freopen("inputf.in", "r", stdin);
#endif
 

    ll t = 1;

    cin >> t;
    while (t--) {
        solve();
        cout << ln;
    }
    return 0;
}
