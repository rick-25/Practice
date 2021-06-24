#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include "ds.h"

using namespace std;

#define ln '\n'
#define ll long long
#define MOD 1000000007


class Solution {
	vector<vector<vector<int>>> memo;

	//Posible moves (Up, Right, Down, Left)
	int rows, coloums;
	int maxMoves;
	int vec[4][2] = {
		{-1, 0},
		{0, 1},
		{1, 0},
		{0, -1}
	};

	bool isValid(int r, int c) {
		if(r < 0 || c < 0 || r >= rows || c >= coloums)
			return false;
		return true;
	}

	int dfs(int r, int c, int remMoves) {

		if(!isValid(r, c))	
			return 1;
		if(!remMoves)
			return 0;
		if(memo[r][c][remMoves] > -1)
			return memo[r][c][remMoves];

		int ans = 0;
		for(int i=0; i<4; i++) 
			ans = (ans % MOD + dfs(r+vec[i][0], c+vec[i][1], remMoves-1) % MOD) % MOD;
		

		memo[r][c][remMoves] = ans;
		return memo[r][c][remMoves];
	}

public:
	//The idea is to do dfs to count all possible path and also use dp to store ans for each cell(since cycle is allowed o.O)
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

		memo = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));  
		rows = m;
		coloums = n;
		maxMoves = maxMove;

		return dfs(startRow, startColumn, maxMove);
    }
};

int main()
{	//Test the solution code here

	Solution object;
	cout << object.findPaths(1, 3, 3, 0, 1) << ln;

	return 0;
}

