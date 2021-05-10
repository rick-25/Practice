#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <set>  
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ln '\n'
#define ll long long

struct Solution {
    bool isPossible(vector<int>& v) {

    	ll sum = accumulate(v.begin(), v.end(), 0);

    	make_heap(v.begin(), v.end());

    	return solve(v, sum);
    }

    bool solve(vector<int> &v, ll sum) {

    	int num = v.front(); 	if(num == 1)	return true;

    	pop_heap(v.begin(), v.end());
    	v.pop_back();

    	sum -= num;

    	if(num <= sum || sum < 1)	return false;

    	num %= sum;
    	sum += num;
    

    	v.push_back(num);
    	push_heap(v.begin(), v.end());

    	return solve(v, sum);
    } 
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	Solution obj;

	vector<int> v = {1, 2};
	cout << obj.isPossible(v);
	return 0;
}