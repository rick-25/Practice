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
	for(int i=0; i<3; i++) {
		for(int j=0; j<8; j++) {
			cout << pow(2, i) << '^' << j << '=' << ((int)pow(2, i) ^ j) << ln; 
		}
	}
}

int main()
{
	//freopen("inputf.in", "r", stdin);
	ll t = 1;
	
	//cin >> t;
	while (t--)
		solve();
	return 0;
}

