#include <iostream>

using namespace std;


struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr)
	{}
	void print();
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

struct TreeNode 
{
	int val;
	TreeNode * left;
	TreeNode * right;

	TreeNode(int x) : val(x), left(nullptr), right(nullptr)
	{}
};
