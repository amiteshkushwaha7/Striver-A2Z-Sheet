// User function Template for C++`
/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) 
    {
        Node* head = *head_ref;
        if(head->data == x)
        {
            Node* start = head;
            while(start!=NULL && start->data == x) start = start->next;
            *head_ref = start;
            while(head!=start)
            {
                Node* temp = head;
                head = head->next;
            //   *head_ref = head;
                temp->next->prev = NULL;
                temp->next = NULL;
                delete(temp);
            }
            
            
        //     head = start;
        //     if(start != NULL)
        //         start->prev = NULL;
        }
        
        Node* start = head;
        while(start)
        {
            if(start->data == x && start->next == NULL)
            {
                start->prev->next = NULL;
                delete(start);
            }
            else if(start->data == x)
            {
                Node* temp = start;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                start = start->next;
                delete(temp);
            }
            else{
            
            start = start->next;
            }
        }
    }
};