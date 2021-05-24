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


class Solution 
{
public:
    string shortestSuperstring(vector<string>& words) 
	{
		unordered_map<string, int> okay[words.size()]; 
		for(int i=0; i<words.size(); i++) 
			okay[i] = solve(words, i);
		
    }

	void solve(vector<string>& words, unordered_map<string, int> okay[], int root, unordered_set<int> used)
	{
		
	}

	unordered_map<string, int> solve(vector<string>& words, int i)
	{
		unordered_map<string, int> data;
		for(int j=0; j<words.size(); j++) {
			if(j == i)	continue;
			data[words[j]] = common(words[i], words[j]);
		}
		return data;
	}

	int common(string first, string second) 
	{
		int ans = 0;
		for(int i = first.size()-1, j = 0; i >= 0, j < second.size(); i--, j++) 
		{
			if(first[i] == second[j]) 
				ans++;
			else 
				break;
		}
		return ans;
	}
};


int main()
{	//Test the solution code here
	return 0;
}

