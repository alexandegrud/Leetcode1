/*
Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
*/

#include <iostream>
#include <vector>
#include <algorithm>
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
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == nullptr) {
			return head; 
		}
		ListNode* temp = head; 
		vector<int> answer; 
		while (temp != NULL) {
			answer.push_back(temp->val);
		    temp = temp->next; 
		}
		sort(answer.begin(), answer.end());
		int i = 0;
		temp = head; 
		while (temp != NULL) {
			temp->val = answer[i];
			i++;
			temp = temp->next;
		}
		return head; 
	}
};


int main() {
	size_t count = 0;
	cin >> count;
	int value = 0; 
	ListNode* head = nullptr;
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
	ListNode* result = Solution.sortList(head);
	while (result != NULL) {
		cout << result->val;
		result = result->next;
	}
}