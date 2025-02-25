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
    pair<bool, ListNode*> recPalindromeCheck(ListNode* front, ListNode* back)
    {
        if (!back)
            return make_pair(true, front);

        pair<bool, ListNode*> result = recPalindromeCheck(front, back->next);  

        if (!result.first) return result;   

        if (result.second->val != back->val) 
            return make_pair(false, result.second->next);
        
        return make_pair(true, result.second->next);
    }

    bool isPalindrome(ListNode* head) 
    {
        if (!head || !head->next) return true;  

        auto result = recPalindromeCheck(head, head);
        return result.first; 
    }
};


//Brute Force
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
    ListNode* reverseList(ListNode* start, ListNode* end)
    {
        ListNode* curr = start;
        ListNode* newHead = NULL;
        while(curr != end)
        {
            ListNode* temp = curr;
            curr = curr->next;

            temp->next = newHead;
            newHead = temp;
        }
        return newHead;
    }

    bool isPalindrome(ListNode* head) 
    {
        if(!head || !head->next) 
            return true;
        if(!head->next->next)
            return head->val == head->next->val;
        
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* secondHalfHead = NULL;
        if(fast)
            secondHalfHead = slow->next->next;
        else
            secondHalfHead = slow->next;
        ListNode* firstHalfHead = reverseList(head, slow->next);
        
        ListNode* curr1 = firstHalfHead;
        ListNode* curr2 = secondHalfHead;
        while(curr1 && curr2)
        {
            if(curr1->val != curr2->val) return false;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return true;
    }
};