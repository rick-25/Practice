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

struct Node {
    int data;
    Node * next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        
        stack<long long> largerElements;
        vector<long long> ans(n, -1);

        for(int i=n-1; i>-1; i--) {
            while(largerElements.size() && largerElements.top() <= arr[i]) {
                largerElements.pop();
            }
           
            if(largerElements.size()) 
                ans[i] = largerElements.top();
            
            largerElements.push(arr[i]);
        }
        return ans;
    }
};

int main(int argLen, const char** args)
{	//Test the solution code here

    Solution * ans = new Solution();
    return 0;
}


