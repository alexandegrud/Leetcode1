/*
The inputs to the judge are given as follows (your program is not given these inputs):

intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
listA - The first linked list.
listB - The second linked list.
skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.

Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'

Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        while (headB != NULL) {
            ListNode* temp = headA;
            while (temp != NULL) {
                if (temp == headB) {
                    return headB;
                }
                temp = temp->next;
            }
            headB = headB->next;
        }
        return NULL;
    }
};



int main() {
    // The same part of both lists
    size_t count = 0;
    cin >> count;
    ListNode* Intersected = nullptr;
    int valuemain = 0;
    if (count > 0) {
        cin >> valuemain;
        Intersected = new ListNode(valuemain);
    }
    ListNode* current0 = Intersected;
    for (size_t i = 1; i < count; i++) {
        cin >> valuemain;
        ListNode* nextnode = new ListNode(valuemain);
        current0->next = nextnode;
        current0 = nextnode; 
    }

    // First List
    size_t skipA = 0;
    cin >> skipA;
    ListNode* headA = nullptr;
    int value = 0;
    if (skipA > 0) {
        cin >> value;
        headA = new ListNode(value);
    }
    ListNode* current = headA; 
    for (size_t i = 1; i < skipA; i++) {
        cin >> value;
        ListNode* nextnode = new ListNode(value);
        current->next = nextnode;
        current = nextnode;
    }
    ListNode* temp = headA;
    while (temp != NULL) {
        if (temp->next == nullptr) {
            temp->next = Intersected;
            break;
        }
        temp = temp->next;
    }

    // Second List
    size_t skipB = 0;
    cin >> skipB;
    ListNode* headB = nullptr;
    int value2 = 0;
    if (skipB > 0) {
        cin >> value2;
        headB = new ListNode(value2);
    }
    ListNode* current2 = headB;
    for (size_t i = 1; i < skipB; i++) {
        cin >> value2;
        ListNode* nextNode = new ListNode(value2);
        current2->next = nextNode;
        current2 = nextNode;
    }
    ListNode* temp2 = headB;
    while (temp2 != NULL) {
        if (temp2->next == nullptr) {
            temp2->next = Intersected;
            break;
        }
        temp2 = temp2->next;
    }


    Solution Solution;
    ListNode* result = Solution.getIntersectionNode(headA, headB);
    cout << result->val;

}