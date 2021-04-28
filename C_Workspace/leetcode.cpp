#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ln '\n'
#define ll long long
 


int main() { 
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
#endif
    
   	ll n, x;
   	cin >> n >> x;
   	
   	ll hoursSum = 0;
   	while(n--) 
   	{
   	    ll temp;
   	    cin >> temp;
   	    hoursSum += temp;
   	}

   	if(hoursSum <= 24 - x)
   		cout << "YES" << ln;
   	else 
   		cout << "NO" << ln;
    
    return 0;
}

