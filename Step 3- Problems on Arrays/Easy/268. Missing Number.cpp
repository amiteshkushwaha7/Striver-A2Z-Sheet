class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int rangeSum = 0;
        int numSum = 0;
        for(int i=0; i<=nums.size(); i++)
        {
            rangeSum = rangeSum + i;

            if(i<nums.size())
                numSum = numSum + nums[i];
        } 

        return (rangeSum - numSum);
    }
}; 