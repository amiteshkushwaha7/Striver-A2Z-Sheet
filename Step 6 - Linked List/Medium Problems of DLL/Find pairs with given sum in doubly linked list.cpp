//User function Template for C++
/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int,int>> ans;
        
        Node* forward = head;
        Node* backward = head;
        while(backward->next != NULL) backward = backward->next;
        
        while(forward != backward)
        {
            int sum = forward->data + backward->data;
            if(sum == target)
            {
                ans.push_back({forward->data, backward->data});
                forward = forward->next;
            }
            else if(sum < target) forward = forward->next;
            else backward = backward->prev;
        }
        return ans;
    }
};