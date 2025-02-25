//Optimal
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    { 
        if (!head) return nullptr;  

        Node* curr = head;
        while (curr) 
        {
            Node* newNode = new Node(curr->val);

            newNode->next = curr->next;
            curr->next = newNode;

            curr = newNode->next;
        }

        Node* orgNode = head;
        while (orgNode) 
        {
            Node* newNode = orgNode->next;

            if(orgNode->random) newNode->random = orgNode->random->next;
            else newNode->random = nullptr;

            orgNode = newNode->next;
        }

        Node* ans = new Node(-1);   
        Node* temp = ans;

        orgNode = head;
        while (orgNode) 
        {
            Node* newNode = orgNode->next;

            orgNode->next = newNode->next;  
            orgNode = orgNode->next;

            temp->next = newNode;   
            temp = newNode;
        }

        temp->next = nullptr;   
        return ans->next;       
    }
};

//Beute Force
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        Node* ans = new Node(-1);
        Node* temp = ans;

        map<Node*, Node*> mpp;
        Node* curr = head;
        while(curr)
        {
            Node* newNode = new Node(curr->val);
            temp->next = newNode;
            temp = newNode;

            mpp[curr] = newNode;
            curr =curr->next;
        }

        for(auto it: mpp)
        {
            Node* first = it.first;
            Node* second = it.second;

            second->random = mpp[first->random];
        }

        return ans->next;
    }
};