// User function Template for C++

/*
class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};*/

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) 
    {
        Node* head = new Node();
        if(arr.size() == 0) return head;
        
        head->data = arr[0];
        Node* temp = head;
        for(int i=1; i<arr.size(); i++)
        {
            Node* newNode = new Node(arr[i]);
            
            newNode->prev = temp;
            temp->next = newNode;
            
            temp = newNode;
        }
        return head;
    }
};