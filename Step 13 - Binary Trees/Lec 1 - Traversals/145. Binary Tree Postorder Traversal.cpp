// Iterative approach
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans; 

        stack<TreeNode*> st;
        st.push(root);

        TreeNode* lastVisited = nullptr;

        while (!st.empty()) {
            TreeNode* node = st.top();

            if ((!lastVisited && (node->left || node->right))) 
            {
                if (node->right)
                    st.push(node->right);
                if (node->left)
                    st.push(node->left);
            }
            else if (lastVisited &&
                    (node->left || node->right) &&
                    lastVisited != node->right &&
                    lastVisited != node->left) 
            {
                if (node->right)
                    st.push(node->right);
                if (node->left)
                    st.push(node->left);
            }
            else {
                ans.push_back(node->val);
                lastVisited = node;
                st.pop();
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
        traverse(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverse(root, ans);
        return ans;    
    }
};