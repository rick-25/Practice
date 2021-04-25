#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define ln '\n';
typedef long long ll;

 

int MAX(int a, int b) { return (a > b) ? a : b; }


class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {

        unordered_map<int, int> sumCounts;
        
        int max = 1;

        for(int i=0; i<wall.size(); i++) 
        {
        	max = giveMaxSum(wall, i, max, sumCounts);
        }
        
        return wall.size() - max;
    }

    int giveMaxSum(vector<vector<int>>& wall, int r, int max, unordered_map<int, int>& umap) 
    {
    	int sum = 0;
    	for(int i=0; i<wall[r].size()-1; i++) 
    	{
    		sum += wall[r][i];

			umap[sum]++;

    		max = MAX(max, umap[sum]);
    	}	
    	return max;
    }
};


int main() {    
   	vector<vector<int>> v = {
   		{1,2,2,1},
        {3,1,2},
        {1,3,2},
        {2,4},
        {3,1,2},
        {1,3,1,1}
   	};

   	Solution obj;
   	cout << obj.leastBricks(v) << ln;
    return 0;
}

