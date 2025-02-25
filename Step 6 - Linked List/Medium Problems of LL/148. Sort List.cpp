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
    ListNode* mergeList(ListNode* leftHalf, ListNode* rightHalf)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        ListNode* i = leftHalf;
        ListNode* j = rightHalf;
        while (i && j)
        {
            if (i->val < j->val)
            {
                temp->next = i;
                i = i->next;
            }
            else
            {
                temp->next = j;
                j = j->next;
            }
            temp = temp->next;
        }

        if (i)
            temp->next = i;
        else
            temp->next = j;

        return dummy->next;
    }

    ListNode* findMiddle(ListNode* head)
    {
        ListNode* mid = head;
        ListNode* mover = head->next;
        while (mover && mover->next)
        {
            mid = mid->next;
            mover = mover->next->next;
        }

        return mid;
    }

    ListNode* sortList(ListNode* head) 
    {
        if (!head || !head->next) return head;

        ListNode* middle = findMiddle(head);
        ListNode* leftHalf = head;
        ListNode* rightHalf = middle->next;
        middle->next = NULL;
 
        leftHalf = sortList(leftHalf);
        rightHalf = sortList(rightHalf);

        return mergeList(leftHalf, rightHalf);
    }
};

//Brute Solution
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
    ListNode* conquerList(ListNode*left, ListNode*mid, ListNode*right)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        ListNode* i = left;
        ListNode* j = mid->next;
        while(i != mid->next && j != right->next)
        {
            if(i->val < j->val)
            {
                ListNode* newNode = new ListNode(i->val);
                temp->next = newNode;
                temp = newNode;

                i = i->next;
            }
            else
            {
                ListNode* newNode = new ListNode(j->val);
                temp->next = newNode;
                temp = newNode;
                j = j->next;
            }
        }

        while(i != mid->next)
        {
            ListNode* newNode = new ListNode(i->val);
            temp->next = newNode;
            temp = newNode;

            i = i->next;
        }

        while(j != right->next)
        {
            ListNode* newNode = new ListNode(j->val);
            temp->next = newNode;
            temp = newNode;
            j = j->next;
        }

        temp->next = NULL;
        return dummy->next;
    }

    void devideList(ListNode* left, ListNode*right)
    {
        if(left == right) return;
        if(left->next == right)
        {
            if(left->val > right->val)
                swap(left->val, right->val);
            return;
        }

        ListNode* mid = left;
        ListNode* mover = left->next->next;
        while(mover && mover != right->next)
        {
            mid = mid->next;

            if(mover == right) mover = right->next;
            else mover = mover->next->next;
        }

        devideList(left, mid);
        devideList(mid->next, right);

        ListNode* dummy = conquerList(left, mid, right);

        ListNode* temp = left;
        ListNode* tempDummy = dummy;
        while(tempDummy)
        {
            temp->val = tempDummy->val;

            temp = temp->next;
            tempDummy = tempDummy->next;
        }
    }

    ListNode* sortList(ListNode* head) 
    {
        if(!head || !head->next) return head;

        if(!head->next->next)
        {
            if(head->val > head->next->val) 
                swap(head->val, head->next->val);
            return head;
        }

        ListNode* tail = head;
        while(tail)
        {
            if(!tail->next) break;
            tail = tail->next;
        }

        devideList(head, tail);
        return head;
    }
};