// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "stdafx.h"
#include "stdlib.h"
#include <initializer_list>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
#if 1
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode dummy(0), *tail = &dummy;
		int nextsum = 0;
		while (l1 || l2 || nextsum)
		{

			int sum = 0;
			if (l1)
			{
				sum += l1->val; l1 = l1->next;
			}
			if (l2)
			{
				sum += l2->val; l2 = l2->next;
			}
			tail->next = new ListNode((sum % 10 + nextsum ) % 10);
			nextsum = (nextsum + sum )/ 10;
			tail = tail->next;
		}
		return dummy.next;
	}
#else
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode dummy(0), *tail = &dummy;
		for (div_t sum{ 0, 0 }; sum.quot || l1 || l2; tail = tail->next) {
			if (l1) { sum.quot += l1->val; l1 = l1->next; }
			if (l2) { sum.quot += l2->val; l2 = l2->next; }
			sum = div(sum.quot, 10);
			tail->next = new ListNode(sum.rem);
		}
		return dummy.next;
	}
#endif
};

ListNode *create_linkedlist(std::initializer_list<int> lst)
{
	auto iter = lst.begin();
	ListNode *head = lst.size() ? new ListNode(*iter++) : NULL;
	for (ListNode *cur = head; iter != lst.end(); cur = cur->next)
		cur->next = new ListNode(*iter++);
	return head;
}
int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	ListNode *l1 = create_linkedlist({ 1 });
	ListNode *l2 = create_linkedlist({ 9,999 });
	ListNode *ret = s.addTwoNumbers(l1, l2);
	for (ListNode *cur = ret; cur; cur = cur->next);
//		cout << cur->val << "->";
//	cout << "\b\b  " << endl;
	return 0;
}

