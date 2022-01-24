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
    static bool comp(vector<int>& a, vector<int>& b) {
        if(a[0] != b[0])
            return a[0] < b[0];
        return a[1] < b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);
        long long int prevArrow = points[0][0]-1, ans = 0;
        for(int i=0; i<points.size(); i++) {
            if(points[i][0] > prevArrow) {
                prevArrow = points[i][1];
                ans++;
            } 
        }
        return ans;
    }
};


int main(int argLen, const char** args)
{	//Test the solution code here
    cout << ln;
    Solution * ans = new Solution();
    vector<vector<int>> test = {
        {-2147483648,2147483647}
    };
    cout << ans->findMinArrowShots(test) << ln;
    return 0;
}


