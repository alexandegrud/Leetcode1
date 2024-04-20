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
		ListNode* answer = new ListNode();
		ListNode* current = answer;
		ListNode* temp = head;
		if (head == NULL) {
			return head;
		}
		int size = 0;
		while (temp != NULL) {
			temp = temp->next;
			size++;
		}
		int i = 0;
		int j = 0;
		while (i != size) {
			temp = head;
			while (j != size - i) {
				if (j + 1 == size - i) {
					current->next = temp;
					current = temp;
					current->next = nullptr;
				}
				temp = temp->next;
				j++;
			}
			j = 0;
			i++;
		}
		return answer->next;
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