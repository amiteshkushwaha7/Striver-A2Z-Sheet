class Solution {
public:
    string reverseWords(string s) 
    {
        
        int n = s.length();
        string ans = "";

        int i=0;
        while(i < n)
        {
            if(s[i] == ' ') i++;
            else
            {
                string temp = "";
                while(i<n && s[i] != ' ') temp += s[i++];
                ans = ' ' + temp + ans;
            }
        } 
        ans.erase(0,1);
        return ans;  
    }
};