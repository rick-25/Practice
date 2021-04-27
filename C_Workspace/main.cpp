#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ln '\n'
typedef long long ll;


void solve()	
{
	int n, m;
    cin >> n >> m;

    vector<pair<int, int>> arr(m);
    for(int i=0; i<m; i++)
    {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }

    //solve here

    

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
