class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int l=0, r=0;
        long sum = 0;
             
        while(r<nums.size())
        {
            sum = sum + nums[r];
            while((r-l+1)*(long)nums[r] > sum+k)
            {
                sum = sum - nums[l];
                l++;
            }

            ans = max(ans, r-l+1);
            r++;
        }    

        return ans;
    }
};