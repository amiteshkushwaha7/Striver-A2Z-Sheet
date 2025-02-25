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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head == NULL) return head;
        if(head->next == NULL && n == 1)
        {
            head = NULL;
            return head;
        }

        ListNode* slow = head;
        ListNode* prevSlow = head;
        ListNode* fast = head;

        int cnt = n;
        while(fast && cnt > 0)
        {
            fast = fast->next;
            cnt--;
        }    

        while(slow && fast)
        {
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next;
        }

        if(slow == prevSlow)
        {
            head = slow->next;
            slow->next = NULL;
            delete slow;
            return head;
        }

        prevSlow->next = slow->next;
        slow->next = NULL;
        delete slow;

        return head;
    }
};