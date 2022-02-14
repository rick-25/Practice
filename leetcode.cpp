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
  void help(unordered_map<int, int>& table, vector<int>& arr1, vector<int>& arr2) {
    for(auto i : arr1) {
      for(auto j : arr2) {
        table[i + j]++;
      }
    }
  }
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
      int ans = 0;
      unordered_map<int, int> table1;
      unordered_map<int, int> table2;
      help(table1, nums1, nums2);
      help(table2, nums3, nums4);
      for(auto p : table1) {
        int target = p.first * -1;
        ans += p.second * table2[target];
      }
      return ans;        
    }
};


int main(int argLen, const char** args)
{	  //Test the Solution code here
  cout << "Hello" << ln;
    return 0;
}


