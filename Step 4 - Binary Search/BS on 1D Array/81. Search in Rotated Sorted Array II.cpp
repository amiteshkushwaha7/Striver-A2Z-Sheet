class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
        int n = nums.size();
        if(n == 1 && nums[0] == target) return true;
        else if(n == 1) return false;

        int left = 0, right = n-1;
        while(left <= right)
        {
            int mid = (left + right)/2;

            if(nums[mid] == target) return true;

            if(nums[mid] == nums[right]) 
            {right--; continue;}

            if(nums[mid] == nums[left])
            {left++; continue;}

            if(nums[mid] > nums[right])
            {
                if(target > nums[mid] || target <= nums[right]) 
                    left = mid + 1;
                else right = mid - 1;
            }   
            else if(nums[mid] < nums[right])
            {
                if(target > nums[mid] && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }  
            else return false;       
        }    

        return false;
    }
};