//Optimal 1
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int n = nums.size();
        if(n == 1 && nums[0] == target) return 0;
        else if(n == 1) return -1;

        int left = 0, right = n-1;
        while(left <= right)
        {
            int mid = (left + right)/2;

            if(nums[mid] == target) return mid;

            if(nums[mid] > nums[right])
            {
                if(target > nums[mid] || target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
            else if(nums[mid] < nums[right])
            {
                if(target > nums[mid] && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
            else return -1;
        } 

        return -1; 
    }
};




//Optimal 2
 class Solution {
public:
    int findRight(vector<int>&arr, int indx, int target)
    {
        int left = indx, right = arr.size()-1;
        while(left <= right)
        {
            int mid = (left + right)/2;

            if(arr[mid] == target) return mid;
            else if(target > arr[mid]) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    int findLeft(vector<int>&arr, int indx, int target)
    {
        int left = 0, right = indx;
        while(left <= right)
        {
            int mid = (left + right)/2;

            if(arr[mid] == target) return mid;
            else if(target > arr[mid]) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    int rotationPoint(vector<int>& nums)
    {
        int left = 0, right = nums.size()-1, mid;
        while(left <= right)
        {
            mid = (left + right)/2;
            
            if(nums[mid] > nums[right])  left = mid + 1;
            else if(nums[mid] < nums[right]) right = mid;
            else return mid;
        }

        return mid;
    }

    int search(vector<int>& nums, int target) 
    {
        int n = nums.size();
        if(n == 1 && nums[0] == target) return 0;
        else if(n == 1) return -1;

        int rPoint = rotationPoint(nums);
        if(nums[rPoint] == target) return rPoint;
        
        if(target > nums[rPoint] && target <= nums[n-1])
            return findRight(nums, rPoint+1, target);
        if(rPoint > 0 && target <= nums[rPoint-1] && target >= nums[0]) 
            return findLeft(nums, rPoint-1, target);
        
        return -1;
    }
};