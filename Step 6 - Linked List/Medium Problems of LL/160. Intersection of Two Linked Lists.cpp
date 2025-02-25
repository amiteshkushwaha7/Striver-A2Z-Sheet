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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        int cntA = 0, cntB = 0;
        ListNode* currA = headA;
        ListNode* currB = headB;

        while(currA)
        {
            cntA++;
            currA = currA->next;
        }

        while(currB)
        {
            cntB++;
            currB = currB->next;
        }  

        
        currA = headA;
        currB = headB;

        if(cntA > cntB)
        {
            int diff = cntA - cntB;
            while(diff > 0)
            {
                diff--;
                currA = currA->next;
            }
        }
        else if(cntB > cntA)
        {
            int diff = cntB - cntA;
            while(diff > 0)
            {
                diff--;
                currB = currB->next;
            }
        }

        while(currA && currB)
        {
            if(currA == currB) 
                return currA;
            
            currA = currA->next;
            currB = currB->next;
        }
        return NULL;
    }
};