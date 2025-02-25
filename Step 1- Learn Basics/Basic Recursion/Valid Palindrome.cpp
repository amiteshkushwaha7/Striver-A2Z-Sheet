class Solution {
public:
    bool isPalindrome(string s) 
    {
        return checkPalindrome(s, 0, s.size()-1);
    }

    bool checkPalindrome(string& s, int i, int j)
    {
        if(i >= j) return true;

        while(i<j && (s[i]==' ' || !(s[i] >= 'A'  && s[i] <='Z') && !(s[i] >= 'a'  && s[i] <='z') && !(s[i] >= '0'  && s[i] <='9'))) i++;
        while(i<j && (s[j]==' ' || !(s[j] >= 'A'  && s[j] <='Z') && !(s[j] >= 'a'  && s[j] <='z') && !(s[j] >= '0'  && s[j] <='9'))) j--;

        if(s[i]>='A' && s[i]<='Z') s[i] = s[i]+32;
        if(s[j]>='A' && s[j]<='Z') s[j] = s[j]+32;

        if(s[i] != s[j]) return false;
        else return checkPalindrome(s, i+1, j-1);
        
        
    }
};