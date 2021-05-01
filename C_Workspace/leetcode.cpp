#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#define ln '\n'
#define ll long long
#define for(s, n) for(int i=s; i<n; i++)
using namespace std;

struct TreeNode 
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int i) : val(i), left(nullptr), right(nullptr)
	{}

	//Helper functinons
	void inorder()
	{
		TreeNode::inorder(this);
	}
	static void inorder(TreeNode* root) 
	{
		if(root == nullptr) return;
		cout << root->val << ' ';
		inorder(root->left);
		inorder(root->right);
	}
	static void insertBST(TreeNode* root, int key )
	{
		if(root == nullptr || root->val == key)	return;
		if(key > root->val)	
		{
			if(root->right == nullptr) 
				root->right = new TreeNode(key);
			else
				insertBST(root->right, key);
		}
		else 
		{
			if(root->left == nullptr)
				root->left = new TreeNode(key);
			else
				insertBST(root->left, key);
		}
	} 
};



int main() 
{
#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	
	return 0;
}