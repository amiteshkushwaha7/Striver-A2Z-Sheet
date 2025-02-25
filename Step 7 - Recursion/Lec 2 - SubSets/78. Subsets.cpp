class Solution {
public:
    void generateSubSets(vector<int> &nums, int indx, vector<int> vec, vector<vector<int>> &ans)
    {
        if(indx == nums.size()) 
        {
            ans.push_back(vec);
            return;
        }

        generateSubSets(nums, indx+1, vec, ans);

        vec.push_back(nums[indx]);
        generateSubSets(nums, indx+1, vec, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        
        vector<vector<int>> ans;
        vector<int> emptyV;
        generateSubSets(nums, 0, emptyV, ans);
        return ans;
    }
};