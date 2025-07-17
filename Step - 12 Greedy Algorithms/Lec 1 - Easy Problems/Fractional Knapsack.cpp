class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        vector<pair<double, int>> factor;
        for(int i = 0; i < n; i++) 
        {
            double ratio = (double)val[i] / wt[i];
            factor.push_back({ratio, i});
        }

        sort(factor.begin(), factor.end(), greater<pair<double, int>>());

        double ans = 0.0;
        for(int i = 0; i < n && capacity > 0; i++) 
        {
            int index = factor[i].second;

            if(wt[index] <= capacity) 
            {
                ans += val[index];
                capacity -= wt[index];
            } else {
                ans += ((double)val[index] / wt[index]) * capacity;
                capacity = 0;
            }
        }

        return ans;
    }
};
