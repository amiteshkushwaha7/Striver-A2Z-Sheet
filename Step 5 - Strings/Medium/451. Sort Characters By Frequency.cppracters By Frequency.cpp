class Solution {
public:
    string frequencySort(string s) 
    {
        int n = s.size();
        map<char,int> mpp;
        for(int i=0; i<n; i++)
        {
            if(mpp.find(s[i]) == mpp.end())
                mpp[s[i]] = 1;
            else mpp[s[i]]++;
        }

        set<pair<int,char>> st;
        for(auto it: mpp)
            st.insert({it.second, it.first});

        int k = n-1;
        for(auto it: st)
        {
            for(int i=1; i<=it.first; i++)
                s[k--] = it.second;
        }
        return s;
    }
};