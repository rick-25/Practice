#include <iostream>
using namespace std;

#define ln '\n'
typedef long long ll;


void solve()
{
	ll n, m, x, y, a, b;
	cin >> n >> m >> x >> y >> a >> b;	

	ll theifMoves = (n - x) + (m - y);
	ll policeMoves = max((n-a), (m-b));

	if(policeMoves >= theifMoves)
		cout << "YES" << ln;
	else 
		cout << "NO" << ln;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("inputf.in", "r", stdin);
		freopen("outputf.in", "w", stdout);
	#endif
    
    ll t;
    cin >> t;
    while(t--)	solve();

    return 0;
}

