#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ln '\n'
typedef long long ll;


void solve()	
{
<<<<<<< HEAD
	//TODO : sovle for each test-case
}


=======
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
>>>>>>> 866efd41c3c1e88a2f2534e286e72f953b404901

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
