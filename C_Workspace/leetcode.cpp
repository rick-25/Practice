#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ln '\n';
typedef long long ll;

 class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return solve(obstacleGrid, 0, 0);
    }
    
    int solve(vector<vector<int>>& obstacleGrid, int x, int y) {
        if(!isValid(obstacleGrid, x, y))    return 0;
        
        if(x == obstacleGrid.size()-1 && y == obstacleGrid[0].size()-1)
            return 1;

        return solve(obstacleGrid, x, y+1) + solve(obstacleGrid, x+1, y); 
    }
    
    bool isValid(vector<vector<int>>& obstacleGrid, int x, int y) {
        if(x >= obstacleGrid.size() || x < 0 || y >= obstacleGrid[0].size() || y < 0)
            return false;
        return (obstacleGrid[x][y] == 0);
    }
};


int main() { 
    //TODO : test here

int main() {    
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
#endif
   	//TODO : test here
    string temp = to_string(3) + "ahelo";
    cout << temp << ln;
    return 0;
}

