// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        int n = bt.size();
        
        sort(bt.begin(), bt.end());
        
        int wt = 0;
        int t = 0;
        
        for(int i=0; i<n; i++)
        {
            wt += t;
            t += bt[i];
        }
        
        double ans = wt/n;
        return ans;
    }
};