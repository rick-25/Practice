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
	char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
	
	int backTrack(string str, int n) {

		if(str.size() == n) {
			return 1;
		}

		int ans = 0;

		char last = (str.size()) ? str[str.size()-1] : '\0';

		for(int i=0; i<5; i++) {
			char cur = vowels[i];
			switch(cur) {
				case 'a' : if(last == 'e' || last == '\0') {
							   str.push_back(cur);
							   ans += backTrack(str, n);
							   str.pop_back();
						   }
						   continue;
				case 'e' : if(last == 'a' || last == 'i' || last == '\0') {
							   str.push_back(cur);
							   ans += backTrack(str, n);
							   str.pop_back();
						   }
						   continue;
				case 'i' : if(last != 'i') {
							   str.push_back(cur);
							   ans += backTrack(str, n);
							   str.pop_back();
						   }
						   continue;
				case 'o' : if(last == 'i' || last == 'u' || last == '\0') {
							   str.push_back(cur);
							   ans += backTrack(str, n);
							   str.pop_back();
						   }
						   continue;

				case 'u' : if(last == '\0' || last == 'a') {
							   str.push_back(cur);
							   ans += backTrack(str, n);
							   str.pop_back();
						   }
						   continue;
			}
		}
		return ans;
	} 
public:
    int countVowelPermutation(int n) {
		string temp;
		return backTrack(temp, n);
    }
};

int main()
{	//Test the solution code here
	int test = 5;
	cout << Solution().countVowelPermutation(test);	
	return 0;
}

