class Solution {
public:
    string removeOuterParentheses(string s) 
    {
        int n = s.size();
        string ans = "";
        int cnt = 0, j = 1; 
        for(int i=0; i<n; i++)
        {
            if(s[i] == '(') cnt++;
            else if(s[i] == ')') cnt--;
            
            if(cnt == 0)
            {
                while(j < i)
                    ans += s[j++];
                j = i + 2;
            }
        }  
        return ans;  
    }
};