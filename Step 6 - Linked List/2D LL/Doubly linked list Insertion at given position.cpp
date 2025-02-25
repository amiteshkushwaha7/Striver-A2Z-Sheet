/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// Function to insert a new node at given position in doubly linked list.
class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) 
    {
        int cnt = -1;
        Node* temp = head;
        while(temp)
        {
            cnt++;
            if(cnt == pos)
            {
                Node* newNode = new Node(data);
                if(temp->next == NULL)
                {
                    newNode->prev = temp;
                    temp->next = newNode;
                }
                else
                {
                    temp->next->prev = newNode;
                    newNode->next = temp->next;
                    newNode->prev = temp;
                    temp->next = newNode;
                }
                return head;
            }
            temp = temp->next;
        }
        return head;
    }
};