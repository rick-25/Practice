#include <bits/stdc++.h>
#include "./notes/algos/SegmentTree.h"

using namespace std;

#define ln '\n'
#define sp ' '
#define ll long long
#define MOD 1000000007

const int MAX_N = 1e5 + 5;




//int dp[MAX_N];
//int arr[MAX_N];



void solve() {
    vector<int> arr = {1, 2, 3};
    SegmentTree *st = new SegmentTree(arr);
    st->update(1, 1);
    cout << st->getSum(0, 1);
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
