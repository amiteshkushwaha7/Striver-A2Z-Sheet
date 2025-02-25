class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int i=0, j=0;
        int counter=0;
        while(j<nums.size())
        {
            if(nums[i] == nums[j]) 
            { counter++; j++; }
            else if(counter == 0) i = j;
            else
            { counter--; j++;}
        }   
        
        return nums[i]; 
    }
};