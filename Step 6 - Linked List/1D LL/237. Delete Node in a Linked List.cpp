/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) 
    {
        ListNode* start = node;
        ListNode* end = node->next;

        while(end->next != NULL)
        { 
            swap(start->val, end->val);
            start = start->next;
            end = end->next;
        }
        swap(start->val, end->val);
        start->next = NULL;
    }
};