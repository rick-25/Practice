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
	ll n, z;
	cin >> n >> z;

	vector<ll> arr(n);
	for(int i=0; i<n; i++) 
		cin >> arr[i];

	make_heap(arr.begin(), arr.end());
	
	int ans = 0;
	while(arr.front() > 0 && z > 0) {

		z -= arr.front();

		ll temp = arr.front();
		pop_heap(arr.begin(), arr.end());
		arr.pop_back();

		arr.push_back(temp/2);
		push_heap(arr.begin(), arr.end());

		ans++;
	}

	if(z > 0) {
		cout << "Evacuate" << ln;
	} else {
		cout << ans << ln;
	}
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

