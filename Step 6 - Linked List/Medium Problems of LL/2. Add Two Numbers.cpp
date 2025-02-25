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
    void addRemain(ListNode* curr, int carry)
    {
        ListNode* prevCurr = NULL;
        while(curr && carry)
        {
            int sum = curr->val + carry;

            curr->val = sum % 10;
            carry = sum / 10;

            prevCurr = curr;
            curr = curr->next;
        }

        if(carry)
        {
            ListNode* newNode = new ListNode(1);
            prevCurr->next = newNode;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;

        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        int carry = 0;
        while(curr1 && curr2)
        {
            int sum = curr1->val + curr2->val + carry;

            ListNode* newNode = new ListNode(sum % 10);
            temp->next = newNode;
            temp = newNode;
            
            carry = sum / 10;

            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        if(curr1)
        {
            temp->next = curr1;
            addRemain(curr1, carry);
        }
        else if(curr2)
        {
            temp->next = curr2;
            addRemain(curr2, carry);
        }
        else if(carry)
        {
            ListNode* newNode = new ListNode(1);
            temp->next = newNode;
            temp = newNode;
        }
        else temp->next = NULL;

        return ans->next;
    }
};