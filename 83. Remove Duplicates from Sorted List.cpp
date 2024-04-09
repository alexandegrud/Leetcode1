/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
Input: head = [1,1,2]
Output: [1,2]

Input: head = [1,1,2,3,3]
Output: [1,2,3]
*/

#include <iostream>
using namespace std;


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* main = head;
        ListNode* current = main;
        ListNode* second = head->next;
        while (head != NULL){
            if (second == NULL) {
                current->next = nullptr;
                break;
            }
            if (current->val == second->val) {
                second = second->next;
            }
            else {
                current->next = second;
                current = second;
                second = second->next;
            }
        }
        return main;
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
    ListNode* result = Solution.deleteDuplicates(head);
    while (head != NULL) {
        cout << head->val;
        head = head->next;
    }
}