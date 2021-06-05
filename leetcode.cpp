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


class Solution {
    int toi(char c) 
    {
        return ((int)c - 48);
    }
    char toc(int n)
    {
        return char(n+48);
    }
    int right(int n)
    {
        if(n == 9)  return 0;
        return ++n;
    }
    int left(int n)
    {
        if(n == 0)  return 9;
        return --n;
    }
public:
    int openLock(vector<string>& deadends, string target) 
    {
        
        unordered_set<string> ends;
        for(auto i : deadends)  ends.insert(i);

        queue<string> tree; 
        tree.push("0000");
        unordered_set<string> seen;
        seen.insert("0000");

        int level = 0;
        while(!tree.empty())
        {
            level++; 
            int len = tree.size();

            for(int j=0; j<len; j++)
            {
                string root = tree.front();
                tree.pop();
            
                if(ends.find(root) != ends.end())   continue;
                if(root == target)  return --level;

                for(int i=0; i<4; i++)
                {
                    string temp = root;

                    temp[i] = toc(right(toi(root[i])));
                    if(seen.find(temp) == seen.end())
                    {
                        tree.push(temp);
                        seen.insert(temp);
                    }

                    temp[i] = toc(left(toi(root[i])));
                    if(seen.find(temp) == seen.end())
                    {
                        tree.push(temp);
                        seen.insert(temp);
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{	//Test the solution code here
    Solution obj;
    vector<string> deadends = {"2000"};
    string target = "1000";

    cout << obj.openLock(deadends, target) << ln;
	return 0;
}

