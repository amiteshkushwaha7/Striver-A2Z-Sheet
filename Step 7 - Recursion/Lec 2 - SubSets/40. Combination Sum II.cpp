class Solution {
public:
    void generateSubSets(vector<int> &input, int indx, vector<int> subSet, vector<vector<int>> &ans, int sum, int target)
    {
        if(sum > target) return;

        if(indx >= input.size())
        {
            if(sum == target) ans.push_back(subSet);
            return;
        }

        subSet.push_back(input[indx]);
        generateSubSets(input, indx+1, subSet, ans, sum+input[indx], target);

        subSet.pop_back();
        int i = indx + 1;
        while(i < input.size() && input[i] == input[i-1]) i++;

        generateSubSets(input, i, subSet, ans, sum, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());

        vector<int> empty;
        vector<vector<int>> ans;

        generateSubSets(candidates, 0, empty, ans, 0, target);

        return ans;
    }
};