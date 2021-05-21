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

class Solution 
{
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) 
	{
		unordered_map<string, vector<string>> table;
		for(auto i : paths) 
			help(i, table);	
		
		
		vector<vector<string>> ans;
		for(auto i : table)	
			if(i.second.size() > 1)
				ans.push_back(i.second);
		
		return ans;
    }

	void help(string s, unordered_map<string, vector<string>> &table) 
	{
		string dir = "";
		
		string name, content;
		bool inContent = false;
		for(int i=0; i<s.size(); i++) 
		{
			if(dir.size() == 0 && s[i] == ' ')	dir = s.substr(0, i);
			
			else if(dir.size() && s[i] != ' ')
			{
				if(s[i] == '(') {
					inContent = true;
				}
				else if(s[i] == ')') {
					inContent = false;
					table[content].push_back(dir+"/"+name);
					name = "";
					content = "";
				}
				else if(inContent) {
					content.push_back(s[i]);
				}
				else {
					name.push_back(s[i]);
				}
			}
			
		}
	}
};

int main()
{
	vector<string> paths = {"root/a 1.txt(one) 2.txt(two)", "root/b 3.txt(one) 4.txt(four)"};
	
	vector<vector<string>> ans = Solution().findDuplicate(paths);

	for(auto v : ans) {
		for(auto s : v)
			cout << s << ' ';
		cout << ln;
	}
	return 0;
}
