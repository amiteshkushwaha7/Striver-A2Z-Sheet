class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int n = nums.size();
        for (int indx=0; indx<n-2; indx++) 
        {
            if (indx > 0 && nums[indx] == nums[indx-1]) continue;

            int diff = 0 - nums[indx];
            int left = indx + 1, right = n - 1;

            while (left < right) 
            {
                int sum = nums[left] + nums[right];
                
                if (sum == diff) 
                {
                    ans.push_back({nums[indx], nums[left], nums[right]});
                    
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    left++;
                    right--;
                } 
                else if (sum < diff) left++;
                else right--;
            }
        }
        return ans;
    }
};