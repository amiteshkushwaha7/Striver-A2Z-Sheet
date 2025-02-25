class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n = nums.size();
        int i,j;
        for(i=n-2; i>=0; i--)
            if(nums[i] < nums[i+1]) break;
        
        if(i == -1)
        {
            int left = 0, right = n-1;
            while(left < right) swap(nums[left++], nums[right--]);
        }
        else
        {
            int elm = INT_MAX, indx;
            for(j=n-1; j>i; j--)
            {
                if(nums[j] > nums[i] && nums[j] < elm)
                {
                    elm = nums[j]; 
                    indx = j;
                }
            }

            swap(nums[i], nums[indx]);

            int left = i+1, right = n-1;
            while(left < right)
                swap(nums[left++], nums[right--]);
        }
    }
};