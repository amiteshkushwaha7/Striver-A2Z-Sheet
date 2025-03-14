//Optimal
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
    ListNode* recReverseList(ListNode* preCurr, ListNode* curr)
    {
        if(!curr->next) 
        {
            curr->next = preCurr;
            preCurr->next = NULL;
            return curr;
        }

        ListNode* newHead = recReverseList(curr, curr->next);
        curr->next = preCurr;
        preCurr->next = NULL;

        return newHead;
    }

    ListNode* reverseList(ListNode* head) 
    {
        if(!head || !head->next) return head;

        return recReverseList(head, head->next);
    }
};