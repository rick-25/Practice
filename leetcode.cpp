#include <bits/stdc++.h>
#include <stack>

#include "ds.h"

using namespace std;

#define ln '\n'
#define ll long long
#define MOD 1000000007

const int MAX_N = 1e5 + 5;

/int dp[MAX_N];
//int arr[MAX_N];

void stackInOrder(TreeNode* root) {
    stack<TreeNode*> in;
    stack<TreeNode*> out;
    in.push(root);
    while(in.size() || out.size()) {
        TreeNode* cur = nullptr;
        if(in.size()) {
            cur = in.top();
            in.pop();
            if(cur->left) in.push(cur->left); 
            out.push(cur); 
        } else {
            cur = out.top();
            out.pop();
            cout << cur->val;
            if(cur->right) in.push(cur->right);
        }
    }
}

int main(const int argLen, const char** args)
{	
    cout << ln;
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    stackInOrder(root);
    return 0;
}


