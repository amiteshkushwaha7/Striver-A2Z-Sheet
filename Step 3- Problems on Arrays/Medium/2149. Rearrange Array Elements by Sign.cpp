class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {    
        vector<int> vec;
        int n = nums.size();
        int i=0, j=0;
        while(i<n || j<n)
        {
            while(i<n && nums[i] < 0) i++;
            if(i<n) vec.push_back(nums[i++]);

            while(j<n && nums[j] > 0) j++;
            if(j<n) vec.push_back(nums[j++]);
        }

        return vec;
    }
};