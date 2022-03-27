#include <iostream>
#include <vector>

using namespace std;


struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr)
    {}
    void print();
    int size();
    static ListNode* toList(vector<int>& arr) 
    {
        if(!arr.size())
            return nullptr;
        ListNode *head = new ListNode(arr[0]);
        ListNode *r = head;
        for(int i=1; i<arr.size(); i++) {
            r->next = new ListNode(arr[i]);
            r = r->next;
        }
        return head;
    }
};

void ListNode::print() 
{
    ListNode * head = this;
    while(head != nullptr) 
    {
        cout << head->val << ' ';
        head = head->next;
    }	cout << endl;
}
int ListNode::size() 
{
    int i = 0;
    ListNode * temp = this;
    while(temp != nullptr) {
        i++;
        temp = temp->next;
    }
    return i;
}

struct TreeNode 
{
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {}
};

void preorder(TreeNode * root)
{
    if(root == nullptr)	return;
    cout << root->val << ' ';
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root)
{
    if(root == nullptr)	return;
    inorder(root->left);
    cout << root->val << ' ';
    inorder(root->right);
}


