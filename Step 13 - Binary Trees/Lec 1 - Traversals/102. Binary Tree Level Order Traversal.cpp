// Approach 1
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        
        vector<vector<int>> ans;

        queue<TreeNode*> qu;
        qu.push(root);
        int size = qu.size();
        vector<int> vec;
        
        while(!qu.empty())
        {
            TreeNode* node = qu.front();

            vec.push_back(node->val);
            
            if(node->left)
                qu.push(node->left);
            if(node->right)
                qu.push(node->right);

            qu.pop();

            if(vec.size() == size)
            {
                ans.push_back(vec);
                size = qu.size();
                vec = vector<int>();
            }
        }
        
        return ans;
    }
};


// Approach 2
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
    void traverse(TreeNode* root, unordered_map<int, vector<int>>& mpp, int level)
    {
        if(!root)
        {
            level -= 1;
            return;
        }

        mpp[level].push_back(root->val);
        traverse(root->left, mpp, level + 1);
        traverse(root->right, mpp, level + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        unordered_map<int, vector<int>> mpp;

        traverse(root, mpp, 0);  // assuming keys start from 1

        int maxKey = INT_MIN;
        for (auto it = mpp.begin(); it != mpp.end(); ++it)
            maxKey = max(maxKey, it->first);

        // Allocate vector with size (maxKey + 1) to include index maxKey
        vector<vector<int>> ans(maxKey + 1);

        for (auto it = mpp.begin(); it != mpp.end(); ++it)
            ans[it->first] = it->second;

        return ans;

    }
};