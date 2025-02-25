/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int loopLength(Node* curr, Node* mover)
    {
        int len = 1;
        while(curr != mover)
        {
            len++;
            mover = mover->next;
        }
        return len;
    }
    
    int countNodesinLoop(Node *head) 
    {
        if(head == NULL || head->next == NULL)
            return 0;
        
        Node* curr = head;
        Node* mover = head->next->next;
        while(curr != NULL && mover != NULL)
        {
            if(curr == mover)
                return loopLength(curr, mover->next);
            
            curr = curr->next;
            if(mover->next == NULL) return 0;
            mover = mover->next->next;
        }
        
        return 0;
    }
};