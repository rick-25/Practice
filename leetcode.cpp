#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#include "ds.h"

using namespace std;

#define ln '\n'
#define ll long long



class Solution {
public:
    int longestStrChain(vector<string>& words) {
		
		sort(words.begin(), words.end(), [](const std::string &word1, const std::string &word2) {
            return word1.size() < word2.size();
        });
		
		int ans = 0;
		unordered_map<string, int> dp;
		for(string &s : words) {
			int len = 1;
			
			for(int i=0; i<s.size(); i++) {
				string temp = s.substr(0, i) + s.substr(i+1, s.size());
				if(dp.find(temp) != dp.end()) {
					len = max(len, dp[temp] + 1);
				}
			}

			dp[s] = len;

			ans = max(ans, dp[s]);
		}
		return ans;
	}
};



int main()
{
	vector<string> test = {"abcd","abc","bcd","abd","ab", "ad", "b"};
	Solution obj;

	cout << obj.longestStrChain(test) << ln;
	return 0;
}
