#include <bits/stdc++.h>

#include "ds.h"

using namespace std;

#define ln '\n'
#define ll long long
#define MOD 1000000007

const int MAX_N = 1e5 + 5;

//int dp[MAX_N];
//int arr[MAX_N];


class Solution {
public:
    bool find132pattern(const vector<int>& nums) {

        if(nums.size() < 3) return false; 

        int third = INT_MIN;
        stack<int> stk; 

        for(int i=nums.size()-1; i >= 1; i--) {
            int cur = nums[i];
            while(stk.size() && stk.top() <= cur) {
                third = stk.top();
                stk.pop();
            }
             
        }
        return false;
    }
};


int main(const int argLen, const char** args)
{	
    cout << ln;
    vector<int> arr = {1, 3, 2, 3};
    cout << (new Solution())->find132pattern(arr);
    return 0;
}


