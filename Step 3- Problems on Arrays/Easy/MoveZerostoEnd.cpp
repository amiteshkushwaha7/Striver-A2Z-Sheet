class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto i = nums.begin();
        int countZeros = 0;
        while(i != nums.end())
        {
            if(*i == 0)
            {
                i = nums.erase(i);
                countZeros++;
            }
            else i++;
        }

        nums.insert(nums.end(), countZeros, 0);
    }
};