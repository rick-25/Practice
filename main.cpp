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

ll rem;


void solve()
{
	ll n, d;
	cin >> n >> d;
	vector<ll> price(n);
	vector<ll> sweetness(n);

	for(int i=0; i<n; i++) 
		cin >> price[i];
	for(int i=0; i<n; i++) 
		cin >> sweetness[i];
}

int main()
{
	//freopen("inputf.in", "r", stdin);
	ll t = 1;
	
	cin >> t;
	while (t--)
		solve();
	return 0;
}

