//Optimal
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        map<int,int> mpp;

        int n = nums.size();
        int count = 0, sum = 0;
        for(int i=0; i<n; i++)
        {
            sum = sum + nums[i];
        
            if(sum == k) 
                count++;
            if(mpp.find(sum-k) != mpp.end()) 
                count = count + mpp[sum-k];

            if(mpp.find(sum) == mpp.end()) 
                mpp[sum] = 1;
            else 
                mpp[sum]++; 
        }

        return count;
    }
};




//Brute Force
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {  
        int n = nums.size();
        int count = 0;
        for(int i=0; i<n; i++)
        {
            int sum = 0;
            for(int j=i; j<n; j++)
            {
                sum = sum + nums[j];
                if(sum == k) count++;
            }
        }

        return count;
    }
};