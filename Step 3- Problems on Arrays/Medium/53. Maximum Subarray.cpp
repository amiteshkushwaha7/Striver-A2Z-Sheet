class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int n = nums.size();
        int j=0;
        int sum = 0, maxSum = INT_MIN; 
        while(j<n)
        {
            sum = sum + nums[j++];
            maxSum = max(maxSum, sum);
            if(sum <= 0 && j<n) sum = 0;
        }

        return maxSum;
    }
};