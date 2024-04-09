/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
*/


#include <iostream>
#include <list>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* resultnode = new ListNode();
        ListNode* temp = resultnode;
        ListNode* head1 = list1;
        ListNode* head2 = list2;

        if (head1 == NULL) {
            return head2;
        }
        if (head2 == NULL) {
            return head1;
        }
        while (head1 != NULL && head2 != NULL) {
            if (head1->val < head2->val) {
                temp->next = head1;
                temp = head1;
                head1 = head1->next;
            }
            else {
                temp->next = head2;
                temp = head2;
                head2 = head2->next;
            }
        }
        if (head1 != NULL) {
            temp->next = head1;
        }
        if (head2 != NULL) {
            temp->next = head2;
        }
        return resultnode->next;
    }
};


int main()
{ 
    size_t count = 0;
    cin >> count; 
    ListNode* list1 = nullptr;
    int value = 0;
    if (count > 0) {
        cin >> value;
        list1 = new ListNode(value);
    }
    ListNode* current = list1;
    for (size_t i = 1; i < count; i++) {
        cin >> value;
        ListNode* nextNode = new ListNode(value);
        current->next = nextNode;
        current = nextNode; 
    }

    size_t count2 = 0;
    cin >> count2;
    ListNode* list2 = nullptr; 
    int value2 = 0;
    if (count2 > 0) {
        cin >> value2; 
        list2 = new ListNode(value2);
    }
    ListNode* current2 = list2;
    for (size_t i = 1; i < count2; i++) {
        cin >> value2; 
        ListNode* nextNode = new ListNode(value2);
        current2->next = nextNode;
        current2 = nextNode; 
    }
    Solution Solution;
    ListNode* result = Solution.mergeTwoLists(list1, list2);
    while (result != NULL)
    {
        cout << result->val;
        result = result->next;
    }
   
   
}
