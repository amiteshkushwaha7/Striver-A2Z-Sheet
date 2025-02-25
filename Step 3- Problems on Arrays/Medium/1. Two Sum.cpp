//Optimal
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> vec;
        int n = nums.size();

        map<int,int> mpp;
        for(int i=0; i<n; i++)
            mpp[nums[i]] = i;
        
        for(int i=0; i<n; i++)
        {
            auto it = mpp.find(target-nums[i]);
            if(it != mpp.end())
            {
                if(mpp[target-nums[i]] != i)
                {
                    vec.push_back(i);
                    vec.push_back(mpp[target-nums[i]]);
                    break;
                }
            }
        }
        return vec;
    }
};



//Brute Force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> vec;
        int n=nums.size();
        
        for(int i=0; i<n; i++)
        {
            int sum = nums[i];
            bool flag = false;
            for(int j=i+1; j<n; j++)
            {
                sum = sum + nums[j];
                if(sum == target)
                {
                    flag = true;
                    vec.push_back(i);
                    vec.push_back(j);
                    break;
                }
                else sum = sum - nums[j];
            }

            if(flag == true) break;
            sum = 0;
        }

        return vec;
    }
};