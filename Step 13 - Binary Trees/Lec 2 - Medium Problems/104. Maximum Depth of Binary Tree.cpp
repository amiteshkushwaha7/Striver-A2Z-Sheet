/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root, int height, int &maxHeight)
    {
        if(!root)
        {
            height -= 1;
            return;
        }

        maxHeight = max(maxHeight, height);
        traverse(root->left, height+1, maxHeight);
        traverse(root->right, height+1, maxHeight);
    }
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        int maxHeight = 0;
        traverse(root, 1, maxHeight);
        return maxHeight;
    }
};