class Solution {
public:
    int generateAtoi(string s, int i, long long ans, int sign)
    {
        if (i == s.size() || !(s[i] >= '0' && s[i] <= '9')) return ans * sign;

        ans = ans * 10 + (s[i] - '0');
        
        if (sign == 1 && ans > INT_MAX) return INT_MAX;
        if (sign == -1 && -ans < INT_MIN) return INT_MIN;
        return generateAtoi(s, i + 1, ans, sign);
    }

    int skipZeros(string s, int i)
    {
        if (i == s.size()) return -1;
        if (s[i] == '0') return skipZeros(s, i + 1);
        return i;
    }

    int skipLeadingSpaces(string s, int i)
    {
        if (i == s.size()) return -1;
        if (s[i] == ' ') return skipLeadingSpaces(s, i + 1);  
        return i;
    }

    int myAtoi(string s) 
    {
        int startIndx, sign = 1;
        long long ans = 0;

        startIndx = skipLeadingSpaces(s, 0);
        if (startIndx == -1) return 0;

        if (s[startIndx] == '-' || s[startIndx] == '+') 
        {
            sign = (s[startIndx] == '-') ? -1 : 1;
            startIndx++;
        }

        startIndx = skipZeros(s, startIndx);
        if (startIndx == -1 || !(s[startIndx] >= '0' && s[startIndx] <= '9')) return 0;
        return generateAtoi(s, startIndx, 0, sign);
    }
};