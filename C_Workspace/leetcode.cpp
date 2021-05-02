#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ln '\n'
#define ll long long

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int i) : val(i), left(nullptr), right(nullptr)
	{
	}

	//Helper functinons
	void preorder()
	{
		TreeNode::preorder(this);
	}
	static void preorder(TreeNode *root)
	{
		if (root == nullptr)
			return;
		cout << root->val << ' ';
		preorder(root->left);
		preorder(root->right);
	}
};

class Solution
{
public:
	vector<TreeNode *> generateTrees(int n)
	{
		// Make a list of all posible left subtree and right subtree and by using do a O(N^2) operation
		// to get all posible arrangements of both subtrees
		vector<int> nodeMap;
		for(int i=1; i<=n; i++)	nodeMap.push_back(i);

		vector<TreeNode *> ans = posibleSubTree(nodeMap, 0, nodeMap.size());
		
		return ans;
	}

private:

	vector<TreeNode *> posibleSubTree(vector<int> &arr, int s, int e)
	{

		vector<TreeNode *> ans;

		for (int i = s; i < e; i++)
		{

			vector<TreeNode *> left = posibleSubTree(arr, s, i);
			vector<TreeNode *> right = posibleSubTree(arr, i + 1, e);

			int leftSize = max((int)left.size(), 1);
			int rightSize = max((int)right.size(), 1);

			for (int p = 0; p < leftSize; p++)
			{
				for (int j = 0; j < rightSize; j++)
				{
					TreeNode *root = new TreeNode(arr[i]);
					root->left = (left.size() > 0) ? left[p] : nullptr;
					root->right = (right.size() > 0) ? right[j] : nullptr;
					ans.push_back(root);
				}
			}
		}

		return ans;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	cout << sizeof(ll) << ln;

	return 0;
}