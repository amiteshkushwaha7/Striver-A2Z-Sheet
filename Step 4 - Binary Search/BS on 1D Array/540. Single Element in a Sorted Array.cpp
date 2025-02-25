class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 1) return nums[0];

        int left = 0, right = n-1;
        while(left <= right)
        {
            int mid = (left + right)/2;

            if(nums[mid] == nums[mid+1])
            {
                int indxSum = mid + right;

                if(indxSum % 2 > 0) right = mid - 1;
                else left = mid;
            }
            else if(nums[mid] == nums[mid-1])
            {
                int indxSum = left + mid;

                if(indxSum % 2 > 0) left = mid + 1;
                else right = mid;
            }
            else return nums[mid];
            
            if(left == right) return nums[left];
        }

        return nums[0];       
    }
};