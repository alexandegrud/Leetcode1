/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:
Input: head = [1], n = 1
Output: []
Example 3:
Input: head = [1,2], n = 1
Output: [1]
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* answer = new ListNode();
        answer->next = head;
        ListNode* first = answer;
        ListNode* second = answer;

        for (int i = 0; i <= n; i++) {
            first = first->next;
        }

        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        ListNode* temp = second->next;
        second->next = second->next->next;
        delete temp;
        return answer->next;
    }

};


int main() {
    size_t count = 0;
    int n = 0;
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
    cin >> n;

    Solution Solution;
    ListNode* result = Solution.removeNthFromEnd(head, n);
    while (result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
}