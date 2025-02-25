class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int n = nums.size();
        for(int a=0; a<n-3; a++)
        {
            if(a>0 && nums[a] == nums[a-1]) continue;

            for(int b=a+1; b<n-2; b++)
            {
                if(b>a+1 && nums[b] == nums[b-1]) continue;

                long long diff = (long long)target - (long long)nums[a] - (long long)nums[b];

                int c = b+1, d = n-1;
                while(c < d)
                {
                    long long sum = (long long)nums[c] + (long long)nums[d];
                    if(sum == diff)
                    {
                        ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                        while(c<d && nums[c] == nums[c+1]) c++;
                        while(c<d && nums[d] == nums[d-1]) d--;

                        c++; d--;
                    }
                    else if(sum < diff) c++;
                    else d--;
                }
            }
        }

        return ans;
    }
};