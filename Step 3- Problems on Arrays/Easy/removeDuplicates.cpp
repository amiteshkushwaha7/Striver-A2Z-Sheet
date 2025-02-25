class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(auto i=nums.begin(); i!=nums.end(); i++)
        {
            auto j=i+1;
            while(j!=nums.end() && *j==*i) 
                j = nums.erase(j);
        }

        return nums.size();
    }
};