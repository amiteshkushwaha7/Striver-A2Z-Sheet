class Solution {
public:
    int beautyNum(map<char,int>& mpp)
    {
        int maxBeauty = INT_MIN;
        int minBeauty = INT_MAX;
        for(auto p: mpp)
        {
            if(p.second >= maxBeauty) maxBeauty = p.second;
            if(p.second <= minBeauty) minBeauty = p.second;
        }
        return maxBeauty - minBeauty;
    }

    int beautySum(string s) 
    {
        int n = s.size();
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            map<char,int> mpp;
            for(int j=i; j<n; j++)
            {
                mpp[s[j]]++;
                sum += beautyNum(mpp);
            }
        }
        return sum;
    }
};