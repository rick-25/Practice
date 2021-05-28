#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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
    //TODO : code here for each test case
	ll n;	cin >> n;
	vector<vector<int>> grid(n);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			int temp;	cin >> temp;
			grid[i].push_back(temp);
		}
	}

}

int main()
{
	ll t = 1;
	
	//cin >> t;
	while (t--)
        solve();

	return 0;
}





