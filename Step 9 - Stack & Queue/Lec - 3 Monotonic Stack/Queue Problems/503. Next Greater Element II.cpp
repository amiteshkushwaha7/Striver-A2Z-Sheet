//Optimal
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);
        vector<pair<bool, int>> vec(n, {false, -1});        
        stack<int> st; 

        for(int i = n - 1; i >= 0; i--) 
        {
            while(!st.empty() && st.top() <= nums[i]) 
                st.pop();
            if(!st.empty()) 
                vec[i] = {true, st.top()};
            st.push(nums[i]);
        }

        for(int i = n - 1; i >= 0; i--) 
        {
            if(vec[i].first == false) 
            {
                while(!st.empty() && st.top() <= nums[i]) 
                    st.pop();
                if(!st.empty()) 
                    vec[i] = {true, st.top()};
                st.push(nums[i]);
            }
        }

        for(int i = 0; i < n; i++)
            ans[i] = vec[i].second;

        return ans;
    }
};
