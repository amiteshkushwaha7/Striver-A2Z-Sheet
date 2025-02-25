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
    ListNode* findStartNode(ListNode* start, ListNode* end)
    {
        while(true)
        {
            if(end->next == start) 
                return start;

            start = start->next;
            end = end->next;
        }
    }
    ListNode *detectCycle(ListNode *head) 
    {
        if(head == NULL || head->next == NULL)
            return NULL;

        ListNode* curr = head;
        ListNode* mover = head->next->next;
        while(curr != NULL && mover != NULL)
        {
            if(curr == mover)
                return findStartNode(head, curr->next);
            
            curr = curr->next;

            if(mover->next == NULL) mover = NULL;
            else mover = mover->next->next;
        }

        return NULL;
        
    }
};