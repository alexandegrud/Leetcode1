/*
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.

Example 1:
Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int answer = 0;
        while (temp != NULL) {
            answer = answer * 2 + temp->val;
            temp = temp->next;
        }
        return answer; 
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
    int result = Solution.getDecimalValue(head);
    cout << result; 
}
