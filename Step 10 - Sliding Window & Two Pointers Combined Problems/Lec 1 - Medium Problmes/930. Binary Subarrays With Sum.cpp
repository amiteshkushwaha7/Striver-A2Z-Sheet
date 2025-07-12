class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        int ans = 0, sum = 0;
        int firstIndx = -1, lastIndx = -1;
        int i = 0, j = 0;

        if(goal == 0)
        {
            int cnt = 0;
            for(int k=0; k<n; k++)
            {
                if(nums[k] == 1)
                {
                    ans += (cnt * (cnt+1))/2;
                    cnt = 0;
                }
                else cnt++;
            }

            ans += (cnt * (cnt+1))/2;
            return ans;
        }

        while(j<n)
        {
            if(sum + nums[j] > goal)
            {
                int left = firstIndx - i;
                int right = j - lastIndx - 1;

                ans += (left*right) + left + right + 1;

                i = firstIndx + 1;
                firstIndx++;
                sum--;
                while(nums[firstIndx] != 1)
                    firstIndx++;
            }

            if(nums[j] == 1)
            {
                if(firstIndx == -1)
                    firstIndx = j;
                lastIndx = j;
            }

            sum += nums[j];

            j++;
        }

        if(sum == goal)
        {
            int left = firstIndx - i;
            int right = j - lastIndx - 1;

            ans += (left*right) + left + right + 1;
        }

        return ans;
    }
};