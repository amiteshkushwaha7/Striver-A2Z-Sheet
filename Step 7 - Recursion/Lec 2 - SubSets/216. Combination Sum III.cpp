class Solution {
public:
    void generateSubSets(int num, vector<int>& subSet, vector<vector<int>>& ans, int sum, int target, int k)
    {
        if (subSet.size() == k) 
        {
            if (sum == target) 
                ans.push_back(subSet);
            return;
        }
 
        if (sum > target || num > 9) return;
 
        subSet.push_back(num);
        generateSubSets(num + 1, subSet, ans, sum + num, target, k);
 
        subSet.pop_back();
        generateSubSets(num + 1, subSet, ans, sum, target, k);
    }

    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<int> empty;
        vector<vector<int>> ans;

        generateSubSets(1, empty, ans, 0, n, k);   

        return ans;  
    }
};