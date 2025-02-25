//Optimal
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {  
        int n = nums.size();
        if(n == 0) return 0;

        set<int> s;
        for(int i=0; i<n; i++)
            s.insert(nums[i]);
        
        int maxLen = 0, tempLen = 1;
        auto i = s.begin();
        auto j = next(i);
        while(j != s.end())
        {
            if(*j-*i == 1) tempLen++;
            else
            {
                maxLen = max(maxLen, tempLen);
                tempLen = 1;
            }

            i++; j++;
        }

        maxLen = max(maxLen, tempLen);
        return maxLen;
    }
};



//Brute Force
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {        
        set<int> s;
        for(int i=0; i<nums.size(); i++)
            s.insert(nums[i]);
        
        int maxLen = 0, tempLen = 1;
        auto i = s.begin();
        auto j = next(i);
        while(j != s.end())
        {
            if(*j-*i == 1) tempLen++;
            else
            {
                maxLen = max(maxLen, tempLen);
                tempLen = 1;
            }

            i++; j++;
        }

        maxLen = max(maxLen, tempLen);
        return maxLen;
    }
};