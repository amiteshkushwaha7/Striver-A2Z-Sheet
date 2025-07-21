// Iterative approach
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        
        TreeNode* node = root;
        vector<int> ans;
        stack<TreeNode*> st;

        while(true)
        {
            if(node)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if(st.empty())
                    break;
                node = st.top();
                st.pop();

                ans.push_back(node->val);
                node = node->right;
            }
        }

        return ans;
    }
};


// Recursive approach
class Solution {
public:
    void traverse(TreeNode* root, vector<int> &ans)
    {
        if(!root)
            return;
        traverse(root->left, ans);
        ans.push_back(root->val);
        traverse(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
};