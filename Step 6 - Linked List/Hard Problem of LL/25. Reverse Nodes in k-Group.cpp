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
    pair<ListNode*, ListNode*> reverseList(ListNode* start, ListNode* end)
    {
        ListNode* newHead = NULL;
        ListNode* curr = start;
        while(curr != end)
        {
            ListNode* temp = curr;
            curr = curr->next;

            temp->next = newHead;
            newHead = temp;
        } 

        curr->next = newHead;
        newHead = curr;

        return make_pair(newHead, start);
    }

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(!head || !head->next || k == 1) 
            return head;

        int len = 0;
        ListNode* first = head;
        ListNode* last = NULL;
        while(first)
        {
            len++;
            if(!first->next) last = first;
            first = first->next;
        }

        if(k > len) return head;
        if(k == len) return (reverseList(head, last)).first;
        
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        first = head;
        while(first)
        {
            int cnt = 0;
            ListNode* start = first;
            ListNode* end = first;
            while(first && cnt < k)
            {
                cnt++;
                end = first;
                first = first->next;
            }

            if(cnt == k)
            {
                auto p = reverseList(start, end);
                temp->next = p.first;
                temp = p.second;
            }
            else {temp->next = start; break;}
        }
        return ans->next;
    }
};