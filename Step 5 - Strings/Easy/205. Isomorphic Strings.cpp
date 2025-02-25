class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        if(s.size() != t.size()) return false;

        int n = s.size();
        map<char,char> sMpp, tMpp;
        for(int i=0; i<n; i++)
        {
            if(sMpp.find(s[i]) == sMpp.end()) sMpp[s[i]] = t[i];
            else if (sMpp[s[i]] != t[i]) return false;

            if(tMpp.find(t[i]) == tMpp.end()) tMpp[t[i]] = s[i];
            else if(tMpp[t[i]] != s[i]) return false;
        }
        return true;
    }
};