class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        
        int len = 0;
        int i = 0, j = 0;
        int flips = k;

        while(j<n)
        {
            if(nums[j] == 0 && flips == 0)
            {
                len = max(len, j-i);

                while(nums[i] == 1)
                    i++;

                i++; flips++;
            }

            if(nums[j] == 0 && flips > 0)
                flips--;

            j++;
        }

        len = max(len, j-i);

        return len;
    }
};