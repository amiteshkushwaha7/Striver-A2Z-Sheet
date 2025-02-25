class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.length() != t.length()) return false; 
        
        map<char,int> mpp;
        char c = 'a';
        int cnt = 1;
        while(cnt <= 26)
        {
            mpp[c] = 0;
            c++; cnt++;
        }

        for(int i=0; i<s.length(); i++)
        {
            mpp[s[i]]++;
            mpp[t[i]]--;
        }

        for(auto i=mpp.begin(); i!=mpp.end(); i++)
            if(i->second != 0) return false;
        return true;    
    }
};