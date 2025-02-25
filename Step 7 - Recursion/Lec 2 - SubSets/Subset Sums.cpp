class Solution {
  public:
    void generateSubSets(vector<int> &arr, int indx, int sum, vector<int> &ans)
    {
        if(indx == arr.size())
        {
            ans.push_back(sum);
            return;
        }
        
        generateSubSets(arr, indx+1, sum, ans);
        
        sum += arr[indx];
        generateSubSets(arr, indx+1, sum, ans);
    }
    
    vector<int> subsetSums(vector<int>& arr) 
    {
        vector<int> ans;

        generateSubSets(arr, 0, 0, ans);
        
        return ans;
    }
};