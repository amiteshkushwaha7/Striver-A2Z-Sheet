/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) 
    {
        if (!head || head->next == NULL) return head;  
    
        DLLNode* last = head;
        while (last->next != NULL) last = last->next;  
            
        DLLNode* start = head;
        while (start != last && start->prev != last) 
        { 
            swap(start->data, last->data);
            start = start->next;  
            last = last->prev;   
        }
    
        return head;
    }
};