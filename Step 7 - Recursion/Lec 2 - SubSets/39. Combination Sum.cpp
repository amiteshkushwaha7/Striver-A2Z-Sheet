class Solution {
public:
    void generateSum(vector<int> &input, int indx, int sum, int k, int target, vector<int> vec, vector<vector<int>> &ans)
    {
        if(sum > target) return;

        if(indx >= input.size())
        {
            if(sum == target) 
                ans.push_back(vec);
            return;
        }

        generateSum(input, indx+1, sum, k, target, vec, ans);

        for(int i=1; i<=k; i++)
        {
            vec.push_back(input[indx]);
            sum = sum + input[indx];

            if(sum > target) return;
            
            generateSum(input, indx+1, sum, k, target, vec, ans);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) 
    {    
        int min = INT_MAX;
        for(int i=0; i<arr.size(); i++)
            if(arr[i] < min) min = arr[i];
        
        int k = target / min;
        
        vector<vector<int>> ans;
        vector<int> empty;
        generateSum(arr, 0, 0, k, target, empty, ans);
        return ans;
    }
};