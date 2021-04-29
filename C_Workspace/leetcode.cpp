#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#define ln '\n'
#define ll long long

using namespace std;



class Solution
{
public:
	static vector<int> spiralOrder(const vector<vector<int>> &A)
 	{
		// TODO : CODE HERE
		
	}
};



int main()
{
#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
	vector<vector<int>> grid = {
		{1, 2, 3}, 
		{5, 6, 7}, 
		{8, 9, 10}
	};

	vector<int> ans = Solution::spiralOrder(grid);
	for(int i=0; i<ans.size(); i++)
		cout << ans[i] <<  ' ';
	cout << ln;
	return 0;
}
