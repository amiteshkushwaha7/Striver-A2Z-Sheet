/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) 
    {
        if(x == 1)
        {
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
            return head;
        }
        
        Node* temp = head;
        int cnt = 0;
        while(temp)
        {
            cnt++;
            if(cnt == x)
            {
                if(temp->next == NULL)
                {
                    temp->prev->next = NULL;
                    delete temp;
                }
                else
                {
                    temp->next->prev = temp->prev;
                    temp->prev->next = temp->next;
                }
                return head;
            }
            temp = temp->next;
        }
        return head;
    }
};