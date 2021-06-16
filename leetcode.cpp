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
	int getCubeNo(int r, int c)
	{
		int rdif = r / 3, cdif = c / 3;
		return (rdif*3) + cdif;
	}
	bool backtrack(vector<vector<char>>& board, int r, int c, unordered_set<char> rows[], unordered_set<char> cols[], unordered_set<char> cubes[])
	{
		if(r == 9)	return true; //Base case

		int tr, tc;
		if(c == 8) {tr = r+1; tc = 0;}
		else {tr = r; tc = c+1;}


		if(board[r][c] != '.')
			return backtrack(board, tr, tc, rows, cols, cubes);
		

		
		int cubeNo = getCubeNo(r, c);
		for(char i='1'; i<='9'; i++)
		{
			if(rows[r].find(i) == rows[r].end() && cols[c].find(i) == cols[c].end() && cubes[cubeNo].find(i) == cubes[cubeNo].end())
			{
				rows[r].insert(i);
				cols[c].insert(i);
				cubes[cubeNo].insert(i);
				board[r][c] = i;


				if(backtrack(board, tr, tc, rows, cols, cubes))
					return true;

				cubes[cubeNo].erase(i);
				cols[c].erase(i);
				rows[r].erase(i);
			}
		}

		board[r][c] = '.';

		return false;
	}
public:
    void solveSudoku(vector<vector<char>>& board) 
	{
		unordered_set<char> rows[9];
		unordered_set<char> cols[9];
		unordered_set<char> cubes[9];

		for(int r=0; r<9; r++)
		{
			for(int c=0; c<9; c++)
			{
				if(board[r][c] == '.')	continue;

				rows[r].insert(board[r][c]);
				cols[c].insert(board[r][c]);
				cubes[getCubeNo(r, c)].insert(board[r][c]);
			}
		}

		backtrack(board, 0, 0, rows, cols, cubes);
    }
};

int main()
{	//Test the solution code here
	cout << sizeof(unordered_set<char>);
	return 0;
}

