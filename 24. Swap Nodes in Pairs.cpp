/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [1]
Output: [1]
*/
#include <iostream>
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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == nullptr) {
            return head;
        }
        ListNode* prev = head;
        while (head != NULL && head->next != nullptr) {
            swap(head->val, head->next->val);
            head = head->next->next;
        }
        return prev; 
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
    ListNode* result = Solution.swapPairs(head);
    while (result != NULL) {
        cout << result->val;
        result = result->next;
    }
}