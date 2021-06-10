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
#define MOD 1000000007

class Solution {
public:
    int maxResult(vector<int>& nums, int k) 
	{
		multiset<int, greater<int> > heap;	
		heap.insert(nums[nums.size()-1]);
		
		for(int i=nums.size()-2; i>-1; i--)
		{
			nums[i] += (*heap.begin()); 
			if(i+k < nums.size())
				heap.erase(heap.find(nums[i+k]));
			heap.insert(nums[i]);	
		}

		return nums[0];
    }
};

int main()
{	//Test the solution code here
	vector<int> test = {10,-5,-2,4,0,3};
	int k = 3;
	cout << Solution().maxResult(test, k);
	return 0;
}

