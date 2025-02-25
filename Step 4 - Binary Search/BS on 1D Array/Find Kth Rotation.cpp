// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &nums) 
    {
        int n = nums.size();
        if(n == 1) return 0;
        
        int left = 0, right = n-1, mid = 0;
        while(left <= right)
        {
            mid = (left + right)/2;
            
            if(nums[mid] > nums[right]) left = mid + 1;
            else if(nums[mid] < nums[right]) right = mid;
            else return mid;
        }
        
        return mid;
    }
};
