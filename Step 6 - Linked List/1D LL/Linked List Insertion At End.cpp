/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) 
    {
        if(head == NULL) 
        {
            Node* temp = new Node(x);
            return temp;
        }
        
        Node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = new Node(x);
        return head;
    }
};