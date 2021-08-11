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
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto i : arr)   mp[i]++;

        sort(arr.begin(), arr.end());

        for(int i : arr) {
            if(mp[i] <= 0)  continue;

            int target = i * 2;
            if(mp.find(target) != mp.end() && mp[target] > 0) {
                mp[i]--;
                mp[target]--;
                continue;
            }
        }

        for(auto p : mp) {
            if(p.second > 0)
                return false;
        }

        return true;
    }
};

int main()
{	//Test the solution code here
    Solution obj;
    vector<int> test = {1,2,1,-8,8,-4,4,-4,2,-2};
    cout << obj.canReorderDoubled(test);
    return 0;
}


