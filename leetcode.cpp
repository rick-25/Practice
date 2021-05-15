#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <numeric> 
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ln '\n'
#define ll long long


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr)
	{}
};


class Solution {
public:
    void flatten(TreeNode* root) {
		solve(root, nullptr); 
    }

	TreeNode* solve(TreeNode *root, TreeNode* prev) {
		if(root == nullptr)	
			return prev;

		prev = solve(root->left, prev);

		if(prev != nullptr) 
			prev -> right = root;

		return solve(root->right, root);
	}
};

void print(TreeNode* root) {
	while(root != nullptr) {
		cout << root -> val << ' ';
		root = root -> right;
	}
}

int main()
{
	TreeNode* temp = new TreeNode(1);
	temp -> left = new TreeNode(2);
	temp -> right = new TreeNode(3);

	Solution().flatten(temp);

	print(temp -> left);

	return 0;
}
