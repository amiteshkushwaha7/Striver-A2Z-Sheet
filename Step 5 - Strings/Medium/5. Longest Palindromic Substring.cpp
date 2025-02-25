class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n = s.size();
        if(n == 1 || n == 0) return s;

        string ans = "";
        for(int i=0; i<n; i++)
        {
            string temp = s.substr(i, 1);
            int start = i-1;
            int end = i+1;
            while((start >= 0 && end < n ) && (s[start] == s[end]))
            {
                temp = s[start] + temp + s[end];
                start--;
                end++;
            }

            if(ans.size() <= temp.size())
                ans = temp;

            temp = "";
            start = i;
            end = i + 1;

            while(start >= 0 && end < n && s[start] == s[end])
            {
                temp = s[start] + temp + s[end];
                start--;
                end++;
            }

            if(ans.size() <= temp.size())
                ans = temp;
        } 
        return ans;  
    }
};