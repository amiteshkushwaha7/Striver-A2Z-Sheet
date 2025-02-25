// User function Template for C++

/*class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};*/

class Solution {
  public:
    Node* constructLL(vector<int>& arr) 
    {
        Node* root = new Node(arr[0]);
        Node* temp = root;
        for(int i=1; i<arr.size(); i++)
        {
            Node* newNode = new Node(arr[i]);
            temp->next = newNode;
            temp = temp->next;
        } 
        return root;
    }
};