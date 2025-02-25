class Solution {
public:
    bool isPossible(vector<int>&arr, int requiredSum, int k)
    {
        int sum = 0, split = 1;
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i] > requiredSum) return false;
            if(sum + arr[i] <= requiredSum) sum += arr[i];
            else
            {split++; sum = arr[i];}
        }
        return split <= k;
    }
    int splitArray(vector<int>& nums, int k) 
    {
        int n = nums.size(), low = INT_MIN, high = 0;
        for(int i=0; i<n; i++)
        {
            low = max(low, nums[i]);
            high += nums[i];
        }
        int ans = -1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(isPossible(nums, mid, k))
            {ans = mid; high = mid - 1;}
            else low = mid + 1;
        }
        return ans;
    }
};