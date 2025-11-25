/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0); // Created a Linked list and We will save this location
        ListNode *tail = dummy;            // We dont want to lose the head, so created a operational linked List whose head is same as Dummy
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {                                           // Checks until its value gets 0. not when the next gets 0. also will keep running until carry is there.
            int v1 = (l1 != nullptr) ? l1->val : 0; // First Checking if that position exist. if yes then saves in v1. if no then gives 0 for that position.
            int v2 = (l2 != nullptr) ? l2->val : 0; // Same here.

            int s = v1 + v2 + carry;
            carry = s / 10;                   // Checks for the carry
            int digit = s % 10;               // Gets the last digit
            tail->next = new ListNode(digit); // Creates a new node replacing the nullptr
            // This will make the node at the head unnecessary.
            tail = tail->next; // Shifts to next node
            if (l1)
                l1 = l1->next; // Checks even if it exists cause sometimes it might end before the another one, if the next node exists then only it shifts to next.
            if (l2)
                l2 = l2->next; // Same
        }
        ListNode *result = dummy->next; // Ignores that extra node at head
        delete dummy;                   // Deletes that extra node
        return result;
    }
};