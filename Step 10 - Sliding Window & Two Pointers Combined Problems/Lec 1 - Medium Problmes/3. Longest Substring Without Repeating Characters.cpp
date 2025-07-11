class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char, bool> alpha;
        for(char ch = 'a'; ch <= 'z'; ch++)
            alpha[ch] = false;

        int i = 0, j = 0;
        int len = 0;
        while(j < s.size())
        {
            if(!alpha[s[j]])
            {
                len = max(len, j-i+1);

                alpha[s[j]] = true;
            }
            else
            {
                if(j == n-1) break;
                while(s[i] != s[j])
                {
                    alpha[s[i]] = false;
                    i++;
                }
                i++;
            }

            j++;
        }   

        return len;
    }
};