class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        
        unordered_map<char,int> mpp;

        int cnt = 0;
        int i = 0, j = 0;
        while(j<n)
        {
            mpp[s[j]]++;

            while(mpp.size() == 3)
            {
                cnt += n-j;
                char c = s[i];

                mpp[c]--;

                if(mpp[c] == 0)
                {
                    mpp.erase(c);
                    i++;
                    break;
                }

                i++;
            }

            j++;
        }

        return cnt;
    }
};