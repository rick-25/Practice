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
	void fill(vector<int>& nums, multiset<int>& s, int i) {
		int x = i;
		for(int y : s) 
				nums[x++] = y; 
	}

public:
    void nextPermutation(vector<int>& nums) 
	{
		multiset<int> s;
		for(int i=nums.size()-1; i>-1; i--)
		{
			s.insert(nums[i]);
			multiset<int>::iterator it = ++s.find(nums[i]);

			if(it == s.end()) 
			{
				if(i == 0) 
					sort(nums.begin(), nums.end());
				continue;
			}
			
			while(it != s.end() && *it <= nums[i]) 
				it++;
			if(it == s.end())	continue;

			int target = *it;
			s.erase(it);

			nums[i] = target;

			fill(nums, s, i+1);
			break;
		}
    }
};

int main()
{	//Test the solution code here

	vector<int> test = {1, 5, 1};
	Solution().nextPermutation(test);

	for(auto i: test)
		cout << i << ' ';

	return 0;
}

