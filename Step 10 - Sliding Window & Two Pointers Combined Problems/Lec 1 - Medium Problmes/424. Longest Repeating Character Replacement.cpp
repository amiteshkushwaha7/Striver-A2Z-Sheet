class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        unordered_map<char,int> mpp;

        int len = 0, maxFeq = 0;
        int i = 0, j = 0;

        while(j<n)
        {
            mpp[s[j]]++;
            maxFeq = max(maxFeq, mpp[s[j]]);

            while((j-i+1-maxFeq) > k)
            {
                mpp[s[i]]--;
                if(mpp[s[i]] == 0)
                    mpp.erase(s[i]);
                i++;
            }

            len = max(len, j-i+1);

            j++;
        }

        return len;
    }
};