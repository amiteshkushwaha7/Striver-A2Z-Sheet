/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/

class Solution
{
public:
    Node* removeDuplicates(struct Node *head)
    {
        if(!head || head->next == NULL) return head;
        
        Node* start = head;
        while(start->next != NULL)
        {
            if(start->data == start->next->data)
            {
                Node* forward = start->next;
                while(forward && forward->data == start->data) 
                    forward = forward->next;
                start->next = forward;
                
                if(forward)
                    forward->prev = start;
                else break;
            }
            
            start = start->next;
        }
        return head;
    }
};