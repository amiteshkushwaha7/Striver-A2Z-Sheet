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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!head || !head->next) return head;
        
        int listLen = 0;
        ListNode* curr = head;

        while(curr->next)
        {
            listLen++;
            curr = curr->next;
        } 
        listLen++;

        k = k % listLen;
        if(k == listLen) return head;

        curr->next = head;

        int skip = listLen - k;
        curr = head;
        for (int i = 1; i < skip; ++i)
            curr = curr->next;
 
        head = curr->next;
        curr->next = NULL;
        return head;
    }
};

//Better 
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
    void reverseList(vector<ListNode*>& vec, int start, int end)
    {
        while(start < end)
        {
            swap(vec[start]->val, vec[end]->val);
            start++;
            end--;
        }
    }

    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!head || k == 0) return head; 

        vector<ListNode*> vec;
        int length = 0;
        ListNode* temp = head;
        while(temp)
        {
            length++; 
            vec.push_back(temp);
            temp = temp->next;
        }

        k = k % length;
        if(k == length) 
            return head;

        reverseList(vec, 0, length - k - 1);
        reverseList(vec, length - k, length - 1);
        reverseList(vec, 0, length-1);
        return head;
    }
};


//Brute force
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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(!head || k == 0) return head; 

        int length = 0;
        ListNode* temp = head;
        while(temp)
        {
            length++;
            temp = temp->next;
        }
        if(k == length) return head;

        k = length - (k % length);
        for(int i=1; i<=k; i++)
        {
            temp = head;
            while(temp->next)
            {
                swap(temp->val, temp->next->val);
                temp = temp->next;
            }
        }
        return head;
    }
};