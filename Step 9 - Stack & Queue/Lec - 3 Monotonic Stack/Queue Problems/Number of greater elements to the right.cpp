//Optimal
// User function Template for C++

class Solution {
  public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) 
    {
        vector<int> ans;
        for(int j=0; j<indices.size(); j++)
        {
            int cnt = 0;
            for(int i=indices[j]+1; i<n; i++)
            {
                if(arr[i] > arr[indices[j]])
                    cnt++;
            }
            ans.push_back(cnt);
        }
        
        return ans;
    }
};



//Brute Solution 
// User function Template for C++

class Solution {
  public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
        vector<int> ans;
        for(int i=0; i<indices.size(); i++)
        {
            int indx = indices[i];
            int cnt = 0;
            for(int j=indx+1; j<arr.size(); j++)
                if(arr[j] > arr[indx]) cnt++;
            ans.push_back(cnt);
        }
        return ans;
    }
};