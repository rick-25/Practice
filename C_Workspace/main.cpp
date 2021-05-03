#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define ln '\n'
#define ll long long

// 2
// 15
// ((A+B)*D)^(E-F)
// 19
// A+(B*C-(D/E^F)*G)*H

// Example Output

// AB+D*EF-^
// ABC*DEF^/G*-H*+

void solve()
{
	ll n;
	string s;
	cin >> n >> s;

	string ans;
	stack<pair<char, int>> stk;
	unordered_set<char> charSet = {'+', '-', '*', '/', '^'};

	ll level = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (charSet.find(s[i]) != charSet.end())
		{
			stk.push({s[i], level});
		}
		else if (s[i] == '(')
		{
			level++;
		}
		else if (s[i] == ')')
		{
			while (!stk.empty() && stk.top().second == level)
			{
				ans.push_back(stk.top().first);
				stk.pop();
			}

			level--;
		}
		else
		{
			ans.push_back(s[i]);
		}
	}

	while (stk.size() > 0)
	{
		ans.push_back(stk.top().first);
		stk.pop();
	}

	cout << ans << ln;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	ll t = 1;
	cin >> t;
	while (t--)
		solve();

	return 0;
}
