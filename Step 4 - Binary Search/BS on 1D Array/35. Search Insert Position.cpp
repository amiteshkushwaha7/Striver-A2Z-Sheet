class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int low = 0, high = n-1, mid;
        while(low <= high)
        {
            mid = (low + high)/2;
            if(nums[mid] == target)
                return mid;
        
            if(target > nums[mid])
                low = mid+1;
            else
                high = mid-1;
        }

        if(target > nums[mid]) return mid+1;
        return mid;    
    }
};