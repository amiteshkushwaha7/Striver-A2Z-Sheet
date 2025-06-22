//Optimal
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        stack<int> st;
        map<int,int> mpp;
        vector<int> ans;

        for(int i=n2-1; i>=0; i--)
        {
            if(st.empty())
                mpp[nums2[i]] = -1;
            else
            {
                while(!st.empty())
                {
                    if(st.top() > nums2[i])
                    {
                        mpp[nums2[i]] = st.top();
                        break;
                    }
                    else st.pop();

                    if(st.empty())
                       mpp[nums2[i]] = -1;
                }
            }
            st.push(nums2[i]);
        }

        for(int i=0; i<n1; i++)
            ans.push_back(mpp[nums1[i]]);

        return ans;
    }
};