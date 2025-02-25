class Solution {
public:
    vector<vector<int>> dp;

    bool generateSubSets(vector<int> &nums, int indx, int sum, int target) 
    {
        if (sum == target) return true;
        if (indx >= nums.size() || sum > target) return false;

        if (dp[indx][sum] != -1) return dp[indx][sum];

        bool exclude = generateSubSets(nums, indx + 1, sum, target);
        bool include = generateSubSets(nums, indx + 1, sum + nums[indx], target);

        return dp[indx][sum] = (include || exclude);
    }

    bool isSubsetSum(vector<int>& arr, int target) 
    {
        dp.resize(arr.size(), vector<int>(target + 1, -1));
        return generateSubSets(arr, 0, 0, target);
    }
};
