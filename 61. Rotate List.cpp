/*
Given the head of a linked list, rotate the list to the right by k places.
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;
        int size = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            size++;
        }

        int rotate = k % size;
        if (rotate == 0)
            return head;

        tail->next = head;
        rotate = size - rotate - 1;
        ListNode* temp = head;

        while (rotate--) {
            temp = temp->next;
        }
        ListNode* forward = temp->next;
        temp->next = NULL;

        return forward;

    }
        
 
};

int main() {
    size_t count = 0; 
    int k = 0;
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
    cin >> k; 

    Solution Solution;
    ListNode* result = Solution.rotateRight(head, k);
    while (result != NULL) {
        cout << result->val;
        result = result->next;
    }
}