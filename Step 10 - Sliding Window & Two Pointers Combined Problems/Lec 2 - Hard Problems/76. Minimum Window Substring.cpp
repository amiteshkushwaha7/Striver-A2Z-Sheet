class Solution {
public:
    string minWindow(string s, string t) 
    {
        int sN = s.size();
        int tN = t.size();

        unordered_map<char,int> tMpp;
        for(int i=0; i<tN; i++)
            tMpp[t[i]]++;  

        int minLen = INT_MAX, sIndx = -1;
        int i = 0, j = 0, cnt = 0; 

        while(j<sN)
        {
            if(tMpp.find(s[j]) != tMpp.end() && tMpp[s[j]] > 0 && s[j] ==)
                cnt++;

            tMpp[s[j]]--;

            while(cnt == tN)
            {
                if(j-i+1 < minLen)
                {
                    minLen = j-i+1;
                    sIndx = i;
                }

                tMpp[s[i]]++;

                if(tMpp[s[i]] > 0)
                    cnt--;
                i++;
            }

            j++;
        }

        return (sIndx == -1) ? "" : s.substr(sIndx, minLen);
    }
};