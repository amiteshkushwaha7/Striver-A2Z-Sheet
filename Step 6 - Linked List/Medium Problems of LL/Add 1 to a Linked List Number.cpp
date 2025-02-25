//Optimal
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    int recAddOne(Node* curr)
    {
        if(!curr->next) 
        {
            if(curr->data + 1 == 10)
            {
                curr->data = 0;
                return 1;
            }
            else curr->data++;
            return 0;
        }
        
        int carry = recAddOne(curr->next);
        if(curr->data + carry == 10)
        {
            curr->data = 0;
            return 1;
        }
        else curr->data = curr->data + carry;
        return 0;
    }
    
    Node* addOne(Node* head) 
    {
        if(!head) return head;
        
        int carry = recAddOne(head);
        if(carry)
        {
            Node* newNode = new Node(1);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};

//Brute Force
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverseList(Node* head)
    {
        Node* curr = head;
        Node* newHead = NULL;
        while(curr)
        {
            Node* temp = curr;
            curr = curr->next;
            
            temp->next = newHead;
            newHead = temp;
        }
        return newHead;
    }
    
    Node* addOne(Node* head) 
    {
        if(head == NULL) 
            return head;
            
        if(head->next == NULL) 
        {
            if(head->data + 1 == 10)
            {
                head->data = 0;
                Node* newNode = new Node(1);
                newNode->next = head;
                head = newNode;
            }
            else head->data++;
            return head;
        }
        
        head = reverseList(head);
        
        Node* curr = head;
        Node* preCurr = NULL;
        int carry = 1;
        while(curr && carry)
        {
            if(curr->data + carry == 10)
                curr->data = 0;
            else
            {
                curr->data++;
                carry = 0;
            }
            
            preCurr = curr;
            curr = curr->next;
        }
        
        if(carry)
        {
            Node* newNode = new Node(1);
            preCurr->next = newNode;
        }
        
        head = reverseList(head);
        return head;
    }
};