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

	
void solve()
{
	ll n, k;
	cin >> n >> k;

	vector<int> arr(n);
	for(int i=0; i<n; i++) 
		cin >> arr[i];
	
	int s = 0;
	int ans =  -1;

	unordered_map<int, int> fI; 
	map<int, int> iF; 

	for(int i=0; i<n; i++) 
	{
		if(fI.find(arr[i]) == fI.end()) //Not in the sequence
		{
			if(fI.size() == k-1) 
			{

				int lastIndex = iF.begin()->first;
				int lastFlavour = iF[lastIndex];

				// cout << lastFlavour << " " << lastIndex << ln;

				fI.erase(lastFlavour);	
				iF.erase(lastIndex);
				s = lastIndex+1;
			}

			fI[arr[i]] = i;
			iF[i] = arr[i];
		}
		else 
		{
			int lastIndex = fI[arr[i]];
			fI[arr[i]] = i;

			iF.erase(lastIndex);	
			iF[i] = arr[i];
		}

		ans = max(ans, i-s);
	}


	cout << ++ans << ln;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	ll t = 1;
	cin >> t;
	while (t--)
		solve();

	return 0;
}





