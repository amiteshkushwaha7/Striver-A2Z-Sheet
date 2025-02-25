class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int countOnes = 0;
        int countMaxOnes = 0;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 1) countOnes++;
            else
            {
                countMaxOnes = max(countOnes, countMaxOnes);
                countOnes = 0;
            }
        }   

        if(countOnes > countMaxOnes) return countOnes;
        return countMaxOnes;
    }
};