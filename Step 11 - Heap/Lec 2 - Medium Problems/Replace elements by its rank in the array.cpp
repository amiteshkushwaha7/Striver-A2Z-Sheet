// User function Template for C++

class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int n) {
        vector<int> vec = arr;
        sort(vec.begin(), vec.end());
        
        map<int,int> mpp;
        int rank = 1;
        for(int i=0; i<n; i++)
        {
            if(mpp.find(vec[i]) == mpp.end())
            {
                mpp[vec[i]] = rank;
                rank++;
            }
        }
        
        vector<int> ans;
        for(int i=0; i<n; i++)
            ans.push_back(mpp[arr[i]]);
        return ans;
    }
};
