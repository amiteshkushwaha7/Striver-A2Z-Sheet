// User function template for C++

class Solution {
  public:
    int countSubstr(string& s, int k) 
    {
        return countAtMostK(s, k) - countAtMostK(s, k - 1);
    }
    
    int countAtMostK(string& s, int k) 
    {
        int n = s.size();
        
        map<char, int> mpp;
        int i = 0, j = 0;
        int cnt = 0;
        while(i < n && j < n)
        {
            mpp[s[j]]++;
            
            while(mpp.size() > k)
            {
                mpp[s[i]]--;
                if(mpp[s[i]] == 0)
                    mpp.erase(s[i]);
                i++;
            }
            
            cnt += (j-i+1);
        
            j++;
        }
        return cnt;
    }
};