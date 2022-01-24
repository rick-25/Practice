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
    string s;
    cin >> s;
    ll ones = 0;
    for(auto bit : s) {
        ones += (bit == '1');
    }

    if(ones == 0 || (ones == 1 && s[s.size()-1] == '1'))
        cout << "NO" << ln;
    else
        cout << "YES" << ln;
}

int main()
{
	//freopen("inputf.in", "r", stdin);
    //cout << ln;
	ll t = 1;
    
	cin >> t;
	while (t--)
		solve();

	return 0;
}

