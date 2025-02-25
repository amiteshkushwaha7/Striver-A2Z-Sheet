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
class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        if(head->next == NULL) return head;

        ListNode* start = head;
        ListNode* end = head->next->next;
        while(end && end->next)
        {
            start = start->next;
            end = end->next->next;
        }

        return start->next;
    }
};