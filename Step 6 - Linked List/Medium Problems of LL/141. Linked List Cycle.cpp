//Optimal
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
    bool hasCycle(ListNode *head) 
    {
        if(head == NULL || head->next == NULL)
            return false;
        
        ListNode* curr = head;
        ListNode* mover = head->next->next;
        while(mover != NULL && mover->next != NULL)
        {
            if(curr == mover)
                return true;
        
            curr = curr->next;
            mover = mover->next->next;
        }

        return false;
    }
};

//Brute Force
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
    bool hasCycle(ListNode *head) 
    {
        if(head == NULL || head->next == NULL) return false;
        map<ListNode*, int> mpp;
        
        ListNode* tail = head;
        while(tail)
        {
            if(mpp.find(tail) == mpp.end())
                mpp[tail] = tail->val;
            else return true;
            
            tail = tail->next;
        }
        return false;
    }
};