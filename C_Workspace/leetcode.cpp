#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define ln '\n';
typedef long long ll;

 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        return solve(grid, 0, 0);
    }
    
    int solve(vector<vector<int>>& grid, int x, int y) {
        if(!isValid(grid, x, y))    return 0;
        
        if(x == grid.size()-1 && y == grid[0].size()-1)
            return 1;

        return solve(grid, x, y+1) + solve(grid, x+1, y); 
    }
    
    bool isValid(vector<vector<int>>& grid, int x, int y) {
        if(x >= grid.size() || x < 0 || y >= grid[0].size() || y < 0)
            return false;
        return (grid[x][y] == 0);
    }
};


int main() { 
    //TODO : test here

    return 0;
}

