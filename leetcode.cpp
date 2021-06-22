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
	bool match(vector<vector<int>>& indexmap, string s)
	{
		int pointers[26];
		for(int i=0; i<26; i++)	pointers[i] = 0;

		int index = -1;
		for(int i=0; i<s.size(); i++)
		{
			char cur = s[i];
			int ind = cur - 'a';


			for( ; pointers[ind] < indexmap[ind].size() && indexmap[ind][pointers[ind]] <= index; pointers[ind]++);
			if(pointers[ind] >= indexmap[ind].size())
				return false;


			index = indexmap[ind][pointers[ind]];
			pointers[ind]++;
		}

		return true;
	}
public:
    int numMatchingSubseq(string s, vector<string>& words) {

        vector<vector<int>> indexmap(26);
        for(int i=0; i<s.size(); i++)
			indexmap[s[i]-'a'].push_back(i);

		int ans = 0;
		for(int i=0; i<words.size(); i++)
		{
			if(words[i].size() <= s.size() && match(indexmap, words[i]))
				ans++;
		}

		return ans;
    }
};

int main()
{	//Test the solution code here
	vector<string> test {"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"};
	string root = "dsahjpjauf";
	cout << Solution().numMatchingSubseq(root, test) << ln;
	return 0;
}

