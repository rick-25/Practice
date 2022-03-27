#include <bits/stdc++.h>

using namespace std;

#define ln '\n'
#define sp ' '
#define ll long long
#define MOD 1000000007

const int MAX_N = 1e5 + 5;

//int dp[MAX_N];
int arr[MAX_N];



void solve() {
    ll a, b; cin >> a >> b;
    cout << a+b;
}

int main() {
    //Fast IO
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#ifndef ONLINE_JUDGE
    cout << ln; freopen("inputf.in", "r", stdin);
#endif

    /////////////////////////////////////////////////////////////

    //memset(dp, -1, sizeof(dp));
    ll t = 1;

    cin >> t;
    while (t--) {
        solve();
        cout << ln;
    }

    return 0;
}

