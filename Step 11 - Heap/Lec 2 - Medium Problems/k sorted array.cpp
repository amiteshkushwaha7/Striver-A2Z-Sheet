class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k) {
        
        vector<int> vec;
        for(int i = 0; i < n; i++)
            vec.push_back(arr[i]);
        sort(vec.begin(), vec.end());
        
        map<int,int> mpp;
        for(int i = 0; i < n; i++)
            mpp[vec[i]] = i;
        
        for(int i = 0; i < n; i++) 
        {
            int s = max(0, mpp[arr[i]] - k);
            int l = min(n - 1, mpp[arr[i]] + k);
            
            if(i >= s && i <= l) continue;
            else return "No";
        }
        
        return "Yes";
    }
};
