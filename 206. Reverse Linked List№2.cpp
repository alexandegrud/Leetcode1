/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Input: head = [1,2]
Output: [2,1]
*/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* prev = nullptr;
		ListNode* next = nullptr;
		while (head != NULL) {
			next = head->next;
			head->next = prev;
			prev = head;
			head = next;
		}
		head = prev;
		return head;
	}
};


int main() {
	size_t count = 0;
	cin >> count;
	ListNode* head = nullptr;
	int value = 0;
	if (count > 0) {
		cin >> value;
		head = new ListNode(value);
	}
	ListNode* current = head;
	for (size_t i = 1; i < count; i++) {
		cin >> value;
		ListNode* nextnode = new ListNode(value);
		current->next = nextnode;
		current = nextnode;
	}

	Solution Solution;
	ListNode* result = Solution.reverseList(head);
	while (result != NULL) {
		cout << result->val << " ";
		result = result->next;
	}

}