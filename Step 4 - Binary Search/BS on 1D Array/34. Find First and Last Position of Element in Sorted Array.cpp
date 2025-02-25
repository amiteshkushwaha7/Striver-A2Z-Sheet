class Solution {
public:
    int findRight(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size()-1;
        int result = -1;
        
        while(left <= right)
        {
            int mid = (left+right)/2;

            if(nums[mid] == target)
            {
                result = mid;
                left = mid+1;
            }
            else if(nums[mid] > target) right = mid-1;
            else left = mid+1;
        }

        return result;
    }

    int findLeft(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size()-1;
        int result = -1;

        while(left <= right)
        {
            int mid = (left+right)/2;

            if(nums[mid] == target)
            {
                result = mid;
                right = mid-1;
            }
            else if(nums[mid] > target) right = mid-1;
            else left = mid+1;
        }

        return result;
    }

    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int first_indx = findLeft(nums, target);
        int last_indx = findRight(nums, target);
        return {first_indx, last_indx};
    }
};