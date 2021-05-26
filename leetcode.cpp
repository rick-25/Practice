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

void PrintStack(stack<int> s)
{
    // If stack is empty then return
    if (s.empty())
        return;
     
 
    int x = s.top();
 
    // Pop the top element of the stack
    s.pop();
 
    // Recursively call the function PrintStack
    PrintStack(s);
 
    // Print the stack element starting
    // from the bottom
    cout << x << " ";
 
    // Push the same element onto the stack
    // to preserve the order
    s.push(x);
}

class Solution {
	int res(int a, int b, char op) 
	{
		switch(op) 
		{
			case '+' : return a + b;
			case '-' : return b - a;
			case '*' : return a * b;
			case '/' : return b / a;
		}
		return 0;
	}	
public:
    int evalRPN(vector<string>& tokens) 
	{

		unordered_set<char> op = {'+', '-', '*', '/'};	        
		stack<int> stk;

		for(string cur : tokens)
		{
			if(op.find(cur[0]) == op.end() || cur.size() > 1) {
				stk.push(stoi(cur));
			}
			else {
				int a = stk.top();
				stk.pop();
				int b = stk.top();
				stk.pop();
				stk.push(res(a, b, cur[0]));
			}
		}
		
		return stk.top();
    }
};

int main()
{	//Test the solution code here
	vector<string> test = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
	cout << Solution().evalRPN(test) << ln;
	return 0;
}

