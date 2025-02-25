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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(!head || !head->next || !head->next->next)
            return head;
            
        ListNode* oddTail = head;
        ListNode* evenHead = head->next;

        ListNode* oddNode = oddTail->next->next;
        ListNode* evenTail = evenHead;
        while(oddNode)
        {
            ListNode* temp = oddNode;

            if(!oddNode->next || !oddNode) oddNode = NULL;
            else oddNode = oddNode->next->next;

            evenTail->next = temp->next;
            evenTail = evenTail->next;

            oddTail->next = temp;
            oddTail = oddTail->next;
            oddTail->next = evenHead;
        }

        return head;
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
    ListNode* oddEvenList(ListNode* head) 
    {
        if (!head || !head->next || !head->next->next)
            return head;

        ListNode* dummy = new ListNode(0); 
        ListNode* temp = dummy;           

        ListNode* oddNode = head;
        while (oddNode) 
        {
            ListNode* newNode = new ListNode(oddNode->val);
            temp->next = newNode;
            temp = newNode;

            if (!oddNode->next || !oddNode->next->next) break;
            oddNode = oddNode->next->next;
        }

        
        ListNode* evenNode = head->next;
        while (evenNode) 
        {
            ListNode* newNode = new ListNode(evenNode->val);
            temp->next = newNode;
            temp = newNode;

            if (!evenNode->next || !evenNode->next->next) break;
            evenNode = evenNode->next->next;
        }

        head = dummy->next;   
        delete dummy;       
        return head;
    }
};