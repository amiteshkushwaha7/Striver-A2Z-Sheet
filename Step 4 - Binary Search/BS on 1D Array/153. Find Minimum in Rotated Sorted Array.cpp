//Optimal 1
class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int n = nums.size();
        int left = 0, right = n - 1, mid;
        while(left <= right)
        {
            mid = (left + right)/2;

            if(nums[mid] > nums[right]) left = mid + 1;
            else if(nums[mid] < nums[right]) right = mid;
            else return nums[mid];
        }

        return nums[mid]; 
    }
};

//Optimal 2
class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int n = nums.size(); 
        if(n == 1) return nums[0];

        int left = 0, right = n - 1;
        while(left <= right)
        {
            int mid = (left + right)/2;

            if(mid == n-1) return nums[mid];
            if(mid == 0 && nums[mid+1] > nums[mid]) return nums[mid];
            if(mid == 0 && nums[mid+1] < nums[mid])
            {left = mid + 1; continue;}
        
            if(nums[mid-1] > nums[mid] && nums[mid+1] > nums[mid])
                return nums[mid];
            else if(nums[mid+1] > nums[mid] && nums[right] > nums[mid]) 
                right = mid - 1;
            else left = mid + 1;
        }

        return nums[0]; 
    }
};