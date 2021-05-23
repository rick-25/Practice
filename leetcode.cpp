#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#include "ds.h"

using namespace std;

#define ln '\n'
#define ll long long

class Solution {
	vector<vector<string>> ans;
public:
    vector<vector<string>> solveNQueens(int n) 
	{
		vector<pair<int, int>> queens;
		solve(n, queens, 0);
		return  ans;
    }

	void solve(int n, vector<pair<int, int>> &queens, int row)
	{
		if(row == n) // Base case
		{
			vector<string> data;
			for(auto i : queens) 
			{
				int col = i.second;
				string temp;
				for(int i=0; i<n; i++) 
				{
					if(i == col)
						temp.push_back('Q');
					else 
						temp.push_back('.');
				}
				data.push_back(temp);
			}
			
			ans.push_back(data);
			return;
		}
		for(int i=0; i<n; i++) 
		{
			if(valid(queens, row, i)) 
			{
				queens.push_back({row, i});
				solve(n, queens, row+1);
				queens.pop_back();
			}
		}
	}

	bool valid(vector<pair<int, int>> &queens, int r, int c) 
	{
		for(pair<int, int> coordinate : queens) {
			if(coordinate.second == c)	return false;

			int diff = r - coordinate.first;

			if(c == coordinate.second + diff || c == coordinate.second - diff)	
				return false;
		}
		return true;
	}
};

int main()
{	//Test the solution code here

	int queens = 9;
	vector<vector<string>> ans = Solution().solveNQueens(queens);

	for(auto i : ans) {
		for(auto j : i) {
			cout << j << ln;
		}	cout << ln << ln << ln;
	}
	return 0;
}

