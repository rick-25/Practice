#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ln '\n'
typedef long long ll;

int arr[long(1e5)];

void solve()	
{
	int n, k;
	cin >> n >> k;

	for(int i=0; i<n; i++)
		cin >> arr[i];

	int mid = n / 2;
	
	if(n % 2 != 0)
		mid++;

	
}

int main() 
{

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
    
    ll t;
    cin >> t;
    while(t--)	solve();

    return 0;
}

