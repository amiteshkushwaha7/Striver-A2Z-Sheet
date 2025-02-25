class Solution {
public:
    bool isPossible(vector<int>&arr, int requiredDays, int m, int k)
    {
        int bouq = 0;       
        int flowers = 0;    

        for (int i = 0; i < arr.size(); i++) 
        {
            if (arr[i] <= requiredDays) 
            {
                flowers++;
                if (flowers == k) 
                { 
                    bouq++;
                    flowers = 0;   
                }
            } 
            else flowers = 0;
            if (bouq == m) return true;
        }

        return bouq == m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int n = bloomDay.size();
        int low = INT_MAX, high = INT_MIN;
        for(int i=0; i<n; i++)
        {
            high = max(high, bloomDay[i]);
            low = min(low, bloomDay[i]);
        }

        int ans = -1;
        while(low <= high)
        {
            int mid = (low + high)/2;

            if(isPossible(bloomDay, mid, m, k))
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};