//Optimal
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int x=0;
        for(int i=0; i<nums.size(); i++)
            x = x^nums[i];
        return x;
    }
};

//Brute Force 
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        for(int i=0; i<nums.size(); i++)
        {
            bool flag = false;
            for(int j=0; j<nums.size(); j++)
            {
                if(nums[i] == nums[j] && i!=j)
                {
                    flag = true;
                    break;
                } 
            }

            if(flag == false) return nums[i];
        }

        return nums[nums.size()-1];  
    }
};