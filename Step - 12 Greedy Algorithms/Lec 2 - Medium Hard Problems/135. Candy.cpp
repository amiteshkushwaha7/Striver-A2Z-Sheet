// Approach 1
class Solution {
public:
    int candy(vector<int>& rat) {
        int n = rat.size();

        int i = 1;
        int ans = 1;
        while(i < n)
        {
            if(rat[i] == rat[i-1])
            {
                ans = ans + 1;
                i++;
                continue;
            }
            
            int peak = 1;
            while(i < n && rat[i] > rat[i-1])
            {
                peak += 1;
                ans += peak;
                i++;
            }

            int down = 1;
            while(i < n && rat[i] < rat[i-1])
            {
                ans += down;
                down += 1;
                i++;
            }


            if(down > peak)
                ans += down - peak;        
        }

        return ans;
    }
};




// Approach 2
class Solution {
public:
    int candy(vector<int>& rat) {
        int n = rat.size();

        vector<int> left(n, 1);
        vector<int> right(n, 1);

        for (int i = 1; i < n; i++) 
        {
            if (rat[i] > rat[i - 1])
                left[i] = left[i - 1] + 1;

            if (rat[n-i-1] > rat[n-i])
                right[n-i-1] = right[n-i] + 1;
        }

        int ans = 0;
        for(int i=0; i<n; i++)
            ans += max(left[i], right[i]);
        return ans;
    }
};