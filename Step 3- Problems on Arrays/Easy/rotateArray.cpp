class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        k = k % nums.size();
        reverse(nums, 0, nums.size()-k-1);
        reverse(nums, nums.size()-k, nums.size()-1);
        reverse(nums, 0, nums.size()-1);
    }

    void reverse(vector<int> &nums, int start, int end)
    {
        while(start < end) swap(nums[start++], nums[end--]);
    }
};