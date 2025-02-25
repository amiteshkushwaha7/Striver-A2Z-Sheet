class Solution {
public:
    int generateAtoi(string s, int indx, int n, bool flag)
    {
        int i = indx + 1;
        if(flag)
            while(s[i] == '0') i++;

        long long ans = 0;
        if(!flag) ans = s[indx] - '0';

        while(i<n)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                if (ans > (INT_MAX - (s[i] - '0')) / 10)
                    return (flag && s[indx] == '-') ? INT_MIN : INT_MAX;
                ans = ans * 10 + (s[i] - '0');
            }
            else break;
            i++;
        }

        if(ans == 0) return 0;
        if(s[indx] == '-' && ans > 0) ans = -1 * ans;
        return ans;
    }

    int myAtoi(string s) 
    {
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            if(s[i] == ' ') continue;
            else if(s[i] == '-' || s[i] == '+')
                return generateAtoi(s, i, n, true);
            else if(s[i] >= '0' && s[i] <= '9')
                return generateAtoi(s, i, n, false);
            else break;
        }
        return 0;
    }
};