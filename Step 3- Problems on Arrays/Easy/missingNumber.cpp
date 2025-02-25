class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        vector<bool> vec(nums.size()+1, false);

        for(int i=0; i<nums.size(); i++) vec[nums[i]] = true;
        
        for(int i=0; i<vec.size(); i++) 
            if(!vec[i]) return i; 

        return nums.size(); 
    }
}; 