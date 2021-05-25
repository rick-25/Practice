#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include "ds.h"

using namespace std;

#define ln '\n'
#define ll long long

class Solution {
public:
    bool checkPossibility(vector<int>& nums) 
	{
		int changesCount = 0;
		for(int i=0; i<nums.size() - 1; i++) 
		{
			if(nums[i+1] < nums[i])
			{
				if((i-1 < 0 || nums[i-1] <= nums[i+1]) || (i+2 >= nums.size() || nums[i+2] >= nums[i]))
				changesCount++;
				else 
					return false;
			}
		}
		return (changesCount < 2);
    }
};

int main()
{	//Test the solution code here
	vector<int> test = {4,2,1};
	cout << Solution().checkPossibility(test) << ln;
	return 0;
}

