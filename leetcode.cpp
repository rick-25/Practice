#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
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
private:
	TreeNode* makeSubtree(vector<int>& preorder, vector<int>& inorder, int ins, int ine, int pres, int pree) 
	{
		if(ins > ine || pres > pree)	return nullptr;

		TreeNode * root = new TreeNode(preorder[pres]);
		
		//Make left and right subtree
		int rootIndexIn;
		for(rootIndexIn=ins; rootIndexIn<=ine && inorder[rootIndexIn] != root->val; rootIndexIn++);


		root->left = makeSubtree(preorder, inorder, ins, rootIndexIn-1, pres+1, pres+(rootIndexIn-ins));
		root->right = makeSubtree(preorder, inorder, rootIndexIn+1, ine, (pres+(rootIndexIn-ins))+1, pree);

		return root;
	}
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
	{
		TreeNode * root = makeSubtree(preorder, inorder, 0, preorder.size()-1, 0, preorder.size() ); 
		return root;
    }
};

int main()
{	//Test the solution code here
	vector<int> pre = {3, 9, 20, 15, 7};
	vector<int> in = {9, 3, 15, 20, 7};

	TreeNode* root = Solution().buildTree(pre, in);

	preorder(root);
	cout << ln;
	inorder(root);

	return 0;
}

