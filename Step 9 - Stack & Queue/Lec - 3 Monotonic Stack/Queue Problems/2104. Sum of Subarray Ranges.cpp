//Optimal
class Solution {
public:
    vector<int> countMin(vector<int> &nums)
    {
        vector<int> left(nums.size());
        vector<int> right(nums.size());
        vector<int> mini(nums.size());

        stack<pair<int,int>> st;

        for(int i=0; i<nums.size(); i++)
        {
            int count = 1;
            while(!st.empty() && st.top().first > nums[i])
            {
                count += st.top().second;
                st.pop();
            }
            left[i] = count;
            st.push({nums[i], count});
        }

        while(!st.empty()) st.pop();

        for(int i=nums.size()-1; i>=0; i--)
        {
            int count = 1;
            while(!st.empty() && st.top().first >= nums[i])
            {
                count += st.top().second;
                st.pop();
            }

            right[i] = count;
            st.push({nums[i], count});
        }

        for(int i=0; i<nums.size(); i++)
            mini[i] = left[i] * right[i];

        return mini;
    }

    vector<int> countMax(vector<int> &nums)
    {
        vector<int> left(nums.size());
        vector<int> right(nums.size());
        vector<int> maxi(nums.size());

        stack<pair<int,int>> st;

        for(int i=0; i<nums.size(); i++)
        {
            int count = 1;
            while(!st.empty() && st.top().first < nums[i])
            {
                count += st.top().second;
                st.pop();
            }
            left[i] = count;
            st.push({nums[i], count});
        }

        while(!st.empty()) st.pop();

        for(int i=nums.size()-1; i>=0; i--)
        {
            int count = 1;
            while(!st.empty() && st.top().first <= nums[i])
            {
                count += st.top().second;
                st.pop();
            }
            right[i] = count;
            st.push({nums[i], count});
        }

        for(int i=0; i<nums.size(); i++)
            maxi[i] = left[i] * right[i];

        return maxi;
    }

    long long subArrayRanges(vector<int>& nums) 
    {
        vector<int> mins =  countMin(nums);
        vector<int> maxs =  countMax(nums);
        
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++)
            ans += (1LL * nums[i] * maxs[i]) - (1LL * nums[i] * mins[i]);
        return ans;
    }
};