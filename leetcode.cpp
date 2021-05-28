#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iterator>
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
    int maximumUniqueSubarray(vector<int>& nums) 
	{
		int ans = INT_MIN;

		vector<int> sum(nums.size());
		sum[0] = nums[0];
		for(int i=1; i<nums.size(); i++)
			sum[i] = nums[i] + sum[i-1];
		
		unordered_map<int, int> m;
		int l = -1; //exclusive

		for(int r=0; r<nums.size(); r++) {

			if(m.find(nums[r]) != m.end()) 
				l = max(m[nums[r]], l);	

			m[nums[r]] = r;
			ans = max(ans, sum[r] - ((l > -1) ? sum[l] : 0));
		}

		return ans;
    }
};


int main()
{	//Test the solution code here

	vector<int> test = {1, 5, 1};
	cout << Solution().maximumUniqueSubarray(test);

	return 0;
}

