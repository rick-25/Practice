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
	static bool valid(const vector<vector<int>> arr, int x, int y) {
		if(x < 0 || y < 0 || x >= arr.size() || y >= arr[0].size())
			return false;
		return true;
	}
	static vector<int> spiralOrder(const vector<vector<int>> &A)
 	{
		// TODO : CODE HERE

		int R = 0; // row
		int D = A[0].size()-1; // coloumn
		int L = A.size()-1; // row
		int U = 0; // coloumn


		vector<int> ans;
		

		while(R <= L && D <= U) {


			//left to right
			int x = R, y = U;
			if(y < D && valid(A, x, y))
			while(y < D) 
				ans.push_back(A[x][y++]);


			//top to bottom
			x = R; y = D;
			if(x < L)
			while(x < L && valid(A, x, y))
				ans.push_back(A[x++][y]);
			else if(U < D && valid(A, x, y)) // // omites logic
				ans.push_back(A[x][y]);


			//right to left
			x = L; y = D;
			if(y > U &&  L > R && valid(A, x, y))
			while(y > U)
				ans.push_back(A[x][y--]);
			else if(R < L && valid(A, x, y)) // omites logic
				ans.push_back(A[x][y]);


			//down to up
			x = L; y = U;
			if(x > R && D > U && valid(A, x, y))
			while(x > R)
				ans.push_back(A[x--][y]);	



			R++;
			D--;
			L--;
			U++;
		}
		
		int len = A.size();
		if(len % 2 != 0 && A[0].size() == len)
			ans.push_back(A[len / 2][len / 2]);

		return ans;
	}
};



int main() 
{
#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
	vector<vector<int>> grid = {
		{1, 2},
		{4, 5},
		{6, 7},

	};

	vector<int> ans = Solution::spiralOrder(grid);

	for(int i=0; i<ans.size(); i++)
		cout << ans[i] <<  ' ';
	cout << ln;

	return 0;
}
