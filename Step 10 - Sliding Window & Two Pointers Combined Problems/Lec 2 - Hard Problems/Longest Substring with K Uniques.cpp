// User function template for C++

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        
        unordered_map<char,int> mpp;
        int i = 0, j = 0;
        int len = -1;
        
        while(j<n)
        {
            mpp[s[j]]++;
            
            if(mpp.size() > k)
            {
                len = max(len, j-i);
                
                while(mpp.size() > k)
                {
                    char ch = s[i];
                    mpp[ch]--;
                    if (mpp[ch] == 0)
                        mpp.erase(ch);  
                    i++;
                }
            }
            
            j++;
        }
        
        if(mpp.size() == k)
            len = max(len, j-i);
        
        return len;
    }
};