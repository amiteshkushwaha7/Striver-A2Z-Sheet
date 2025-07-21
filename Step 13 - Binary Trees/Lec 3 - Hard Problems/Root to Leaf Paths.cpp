/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void findPaths(Node* root, vector<int> vec, vector<vector<int>>& ans)
    {
        if(!root)
            return;
        
        vec.push_back(root->data);
        
        if(!root->left && !root->right)
            ans.push_back(vec);
        else
        {
            findPaths(root->left, vec, ans);
            findPaths(root->right, vec, ans);
        }
        
        vec.pop_back();
    }
    
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> vec;
        
        findPaths(root, vec, ans);
        
        return ans;
    }
};