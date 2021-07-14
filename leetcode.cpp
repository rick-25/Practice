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
    string customSortString(string order, string str) {

        unordered_map<char, int> fMap;
        for(int i=0; i<str.size(); i++) {
            fMap[str[i]]++;
        }

        std::string ans = "";
        for(int i=0; i<order.size(); i++) {
            if(fMap.find(order[i]) == fMap.end())
                continue;
            for(int j=0; j<fMap[order[i]]; j++) {
                ans.push_back(order[i]);
            }
            fMap.erase(order[i]);
        }

        for(auto p : fMap) {
            for(int j=0; j<p.second; j++) {
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};

int main()
{	//Test the solution code here
    Solution object;
    string order = "cba";
    string str = "abcd";
    cout << object.customSortString(order, str);
	return 0;
}

