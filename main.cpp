#include <functional>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <bitset>
using namespace std;

#define ln '\n'
#define sp ' '
#define ll long long
#define MOD 1000000007


void solve() {
    ll n; cin >> n;
    vector<ll> v(n);
    for(auto& i: v)
        cin >> i;
    
}



int main() {
    //Fast IO
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    cout << ln;
    freopen("inputf.in","r",stdin);
#endif
    ll t = 1;

    cin >> t;
    while (t--) {
        solve();
        cout << ln;
    }

    return 0;
}

