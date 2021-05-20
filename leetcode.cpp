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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		queue<TreeNode*> bfs;
		
		if(root == nullptr)	return ans;
		
		bfs.push(root);

		int len = 1; 
		while(len) 
		{
			vector<int> temp;
			
			for(int i=0; i<len; i++) 
			{
				TreeNode * node = bfs.front();
				
				temp.push_back(node -> val);

				if(node -> left != nullptr)
					bfs.push(node -> left);
				if(node -> right != nullptr)
					bfs.push(node -> right);

				bfs.pop();
			}
			ans.push_back(temp);
			len = bfs.size();
		}

		return ans;
    }
};


int main()
{
	TreeNode * root = new TreeNode(1);
	root -> left = new TreeNode(2);
	root -> right = new TreeNode(3);
	
	vector<vector<int>> table =	Solution().levelOrder(root);

	for(auto i : table) {
		for(auto t : i) {
			cout << t << ' ';
		}	cout << ln;
	}

	return 0;
}
