// Iteration approach

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        vector<int> ans;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();

            ans.push_back(node->val);

            if(node->right)
                st.push(node->right);
            if(node->left)
                st.push(node->left);
        }

        return ans;
    }
};

// Recursion approach
class Solution {
public:
    void traverse(TreeNode* root, vector<int>& ans)
    {
        if(!root)
            return;
        ans.push_back(root->val);
        traverse(root->left, ans);
        traverse(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
};