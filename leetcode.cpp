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
        
    }

	TreeNode* solve(TreeNode *root, TreeNode* prev) {
		if(root == nullptr)	return prev;
	}
};

int main()
{
	TreeNode* temp = new TreeNode(1);
	cout << temp->val;
	return 0;
}
