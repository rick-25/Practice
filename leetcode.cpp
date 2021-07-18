#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#include <numeric>
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
int size(ListNode* head) 
{
	int i = 0;
	ListNode * temp = head;
	while(temp != nullptr) {
		i++;
		temp = temp->next;
	}
	return i;
}

public:
    //Passed head is going to be the tail of new list.
    //This functino will return the new head of reversed list.
    pair<ListNode*, ListNode*> reverseList(ListNode* head, int len) 
    {
        //ans[0] == new head, ans[1] == head of next list
        pair<ListNode*, ListNode*> ans = {head, head->next};

        if(!len) {
            return ans;
        }

        ListNode *prev = nullptr, *cur = head, *cum = nullptr;

        while(len) {
            //Pre prosessing
            cum = cur->next;

            //main logic
            cur->next = prev;
            prev = cur;

            //updation
            cur = cum;
            len--;
        }

        ans.first = prev;
        ans.second = cur;
        return ans;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {

        if(!k)
            return head;

        int length = size(head);

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *prev = dummy;
        ListNode *cur = head;

        while(length >= k) {
            pair<ListNode*, ListNode*> meta = reverseList(cur, k); 

            if(prev != nullptr) {
                prev->next = meta.first;
            }

            prev = cur;
            prev->next = meta.second;
            
            cur = meta.second;
            length -= k;
        }

        return dummy->next; 
    }
};

int main()
{	//Test the solution code here
    Solution object;
    vector<int> test = {1, 2, 3, 4, 5, 6};
    ListNode *head = ListNode::toList(test);

    head = object.reverseKGroup(head, 3);
    head->print();

	return 0;
}

