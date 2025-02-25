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
    ListNode* deleteMiddle(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
            return NULL;

        ListNode* prevMid = head;
        ListNode* mid = head;
        ListNode* mover = head->next->next;
        while(mid != NULL && mover != NULL)
        {
            prevMid = mid;
            mid = mid->next;
            if(mover->next == NULL)
                break;
            mover = mover->next->next;
        }

        if(mover == NULL)
        {
            ListNode* temp = mid->next;
            mid->next = temp->next;

            temp->next = NULL;
            delete temp;
        }
        else
        {
            prevMid->next = mid->next;
            mid->next = NULL;
            
            delete mid;
        }

        return head;

    }
};