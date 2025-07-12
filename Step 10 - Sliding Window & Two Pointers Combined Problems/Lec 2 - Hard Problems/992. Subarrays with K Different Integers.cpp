class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int subArrays = 0;
        int i = 0, j = 0;
        
        while(j < n) 
        {
            mpp[nums[j]] = j;
            
            if(mpp.size() > k) 
            {
                int minKey = -1;
                int minValue = INT_MAX;
                
                for (auto& pair : mpp) 
                {
                    if (pair.second < minValue) 
                    {
                        minValue = pair.second;
                        minKey = pair.first;
                    }
                }
                
                i = minValue + 1;
                mpp.erase(minKey);
            }
            
            if(mpp.size() == k) 
            {
                int minValue = INT_MAX;
                for (auto& pair : mpp) 
                {
                    if (pair.second < minValue) 
                        minValue = pair.second;
                }
                subArrays += (minValue - i + 1);
            }
            
            j++;
        }
        
        return subArrays;
    }
};