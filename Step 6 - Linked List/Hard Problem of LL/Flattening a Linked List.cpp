//Brute Force
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) 
    {
        // if(!root || !root->next && root->bottom) 
        //     return root;
            
        vector<int> vec;
        Node* curr = root;
        while(curr)
        {
            Node* temp = curr;
            while(temp)
            {
                vec.push_back(temp->data);
                temp = temp->bottom;
            }
            curr = curr->next;
        }
        
        sort(vec.begin(), vec.end());
        
        Node* ans = new Node(vec[0]);
        Node* temp = ans;
        for(int i=1; i<vec.size(); i++)
        {
            Node* newNode = new Node(vec[i]);
            
            temp->bottom = newNode;
            temp = newNode;
        }
        return ans;
    }
};

//Optimal 1
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) 
    {
        vector<Node*> vec;

        Node* curr = root;
        while (curr) 
        {
            vec.push_back(curr);
            curr = curr->next;
        }
     
        Node* ans = new Node(0); 
        Node* temp = ans;
    
        while (true) 
        {
            int val = INT_MAX;
            int indx = -1;
            for (int i = 0; i < vec.size(); i++) 
            {
                if (vec[i] && vec[i]->data < val) 
                {
                    val = vec[i]->data;
                    indx = i;
                }
            }
    
            if (val == INT_MAX) 
                break;
     
            Node* newNode = new Node(val);
            temp->bottom = newNode;
            temp = newNode;
    
            vec[indx] = vec[indx]->bottom;
        }
        
        return ans->bottom;
    }
};

//Optimal 2
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node* mergeList(Node* l1, Node* l2)
    {
        Node* dummy = new Node(0);
        Node* temp = dummy;
        while(l1 && l2)
        {
            if(l1->data < l2->data)
            {
                temp->bottom = l1;
                l1 = l1->bottom;
            }
            else
            {
                temp->bottom = l2;
                l2 = l2->bottom;
            }
            temp = temp->bottom;
        }
        
        if(l1) 
            temp->bottom = l1;
        else 
            temp->bottom = l2;
            
        return dummy->bottom;
        
    }
    
    Node *flatten(Node *root) 
    {
        if(root == NULL) 
            return NULL;
        
        Node* mergedList = flatten(root->next);
        return mergeList(root, mergedList);
    }
};