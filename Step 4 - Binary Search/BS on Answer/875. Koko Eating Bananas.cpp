//Optimal
class Solution {
public:
    int countBananas(vector<int>&piles, int pile, int h)
    {
        int cnt = 0;
        for(int i=0; i<piles.size(); i++)
        {
            cnt += piles[i]/pile;
            if(piles[i] % pile > 0) cnt++;
            if (cnt > INT_MAX) return INT_MAX;   
            if (cnt > h) break;
        }
        return cnt;
    }

    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int n = piles.size();
        int maxPile = INT_MIN;
        for(int i=0; i<n; i++) maxPile = max(maxPile, piles[i]);

        if(h == n) return maxPile;

        int left = 1, right = maxPile;
        int ans = 1;
        while(left <= right)
        {
            int mid = (left + right)/2;
            int cntHrs = countBananas(piles, mid, h);

            if(cntHrs <= h)
            {
                ans = mid;
                right = mid - 1;
            } 
            else left = mid + 1;
        }

        return ans;
    }
};

//Brute Force
class Solution {
public:
    int countBananas(vector<int>&piles, int pile, int h)
    {
        int cnt = 0;
        for(int i=0; i<piles.size(); i++)
        {
            cnt += piles[i]/pile;
            if(piles[i] % pile > 0) cnt++;
            if (cnt > INT_MAX) return INT_MAX;   
            if (cnt > h) break;
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int n = piles.size();
        int maxPile = INT_MIN;
        for(int i=0; i<n; i++) maxPile = max(maxPile, piles[i]);
        if(h == n) return maxPile;
        
        for(int i=1; i<=maxPile; i++)
        {
            int cntHrs = countBananas(piles, i, h);
            if(cntHrs <= h) return i; 
        }

        return -1;
    }
};