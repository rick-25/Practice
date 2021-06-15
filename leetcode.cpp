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

class Solution 
{
public:
    bool isPal(std::string str)
    {
        int l = 0, r = str.size()-1;

        while(l < r)
            if(str[l++] != str[r--])    return false;
        
        return true;
    }

    string rev(string str)
    {
        string terevmp;
        for(int i=str.size()-1; i>-1; i--)
            terevmp.push_back(str[i]);
        return terevmp;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) 
    {
        vector<vector<int>> ans;
        unordered_map<string, int> revmp;
        unordered_map<string, int> mp;
        unordered_set<string> seen;

        for(int i=0; i<words.size(); i++)
        {
            mp[words[i]] = i;
            revmp[rev(words[i])] = i;
        }

        for(int i=0; i<words.size(); i++)
        {
            if(mp.find("") != mp.end() && mp[""] != i && isPal(words[i]))
            {
                vector<int> temp = {i, mp[""]};
                ans.push_back(temp);
                temp = {mp[""], i};
                ans.push_back(temp);
            }
            string front, back;
            for(int j=0, x=words[i].size()-1; j<words[i].size(); j++, x--)
            {
                front.push_back(words[i][j]);
                back.push_back(words[i][x]);

                if(revmp.find(front) != revmp.end() && revmp[front] != i)
                {
                    if(j == words[i].size()-1 || isPal(words[i].substr(j+1, words[i].size())))
                    {
                        string token = words[i] + ", " + words[revmp[front]];
                        if(seen.find(token) != seen.end())  continue;
                        seen.insert(token);

                        vector<int> terevmpAns = {i, revmp[front]};
                        ans.push_back(terevmpAns);
                    }
                }
                
                if(mp.find(back) != mp.end() && mp[back] != i)
                {
                    if(x == 0 || isPal(words[i].substr(0, x))) 
                    {
                        string token = words[mp[back]] + ", " + words[i];
                        if(seen.find(token) != seen.end())  continue;
                        seen.insert(token);

                        vector<int> tempAns = {mp[back], i};
                        ans.push_back(tempAns);
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{	//Test the solution code here
    vector<string> test = {"abcd","dcba","lls","s","sssll"};
    vector<vector<int>> ans = Solution().palindromePairs(test);
    for(auto i : ans)
        cout << i[0] << ", " << i[1] << ln;
	return 0;
}

