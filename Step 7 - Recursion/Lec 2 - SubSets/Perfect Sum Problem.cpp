class Solution {
  public:
    vector<vector<int>> dp;
    
    int generateSubSets(vector<int> &nums, int indx, int sum, int target)
    {
        if(sum > target) return 0;
        
        if(indx >= nums.size()) return sum == target;
        
        if(dp[indx][sum] != -1) return dp[indx][sum];
        
        int include = generateSubSets(nums, indx+1, sum, target);
        int exclude = generateSubSets(nums, indx+1, sum + nums[indx], target);
        
        return dp[indx][sum] = include + exclude;
    }
    
    int perfectSum(vector<int>& arr, int target) 
    {
        dp.resize(arr.size(), vector<int>(target + 1, -1));
        
        return generateSubSets(arr, 0, 0, target);
    }
};
