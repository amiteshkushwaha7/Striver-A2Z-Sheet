//Optimal 2
/*

  Node is defined as
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
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) 
    {
        if (!head || !head->next) return head;
 
        Node* zeroD = new Node(0);
        Node* oneD = new Node(0);
        Node* twoD = new Node(0);
 
        Node* zero = zeroD;
        Node* one = oneD;
        Node* two = twoD;

        Node* curr = head;
 
        while (curr) 
        {
            if (curr->data == 0) 
            {
                zero->next = curr;
                zero = zero->next;
            } 
            else if (curr->data == 1) 
            {
                one->next = curr;
                one = one->next;
            } 
            else 
            {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }
 
        zero->next = (oneD->next) ? (oneD->next) : (twoD->next);
        one->next = twoD->next;
        two->next = NULL;
 
        head = zeroD->next;

        delete zeroD;
        delete oneD;
        delete twoD;

        return head;
    }
};

//Optimal 1
/*

  Node is defined as
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
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) 
    {
        Node* ans = new Node(0);
        
        Node* zero = ans;
        Node* one = ans;
        Node* two = ans;
        
        Node* tempHead = head;
        while(tempHead)
        {
            Node* newNode = new Node(tempHead->data);
            if(tempHead->data == 0)
            {
                newNode->next = zero->next;
                zero->next = newNode;
                
                if(one == zero) one = newNode;
                if(two == zero) two = newNode;
                zero = newNode;
            }
            else if(tempHead->data == 1)
            {
                newNode->next = one->next;
                one->next = newNode;
                
                if(one == two) two = newNode;
                one = newNode;
            }
            else
            {
                newNode->next = two->next;
                two->next = newNode;
                two = newNode;
            }
            
            tempHead = tempHead->next;
        }
        
        return ans->next;
    }
};


//Brute 
/*

  Node is defined as
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
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) 
    {
        int cntZeros = 0;
        int cntOnes = 0;
        int cntTwos = 0;
        
        Node* temp = head;
        while(temp)
        {
            if(temp->data == 0) cntZeros++;
            else if(temp->data == 1) cntOnes++;
            else cntTwos++;
            
            temp = temp->next;
        }
        
        temp = head;
        while(temp)
        {
            if(cntZeros > 0)
            {
                temp->data = 0;
                cntZeros--;
            }
            else if(cntOnes > 0)
            {
                temp->data = 1;
                cntOnes--;
            }
            else temp->data = 2;
            
            temp = temp->next;
        }
        
        return head;
    }
};