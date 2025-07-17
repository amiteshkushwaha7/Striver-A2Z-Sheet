class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& s) {
        int gN = greed.size();
        int sN = s.size();

        sort(greed.begin(), greed.end());
        sort(s.begin(), s.end());

        int i = 0;
        int j = 0;
        int ans = 0;

        while(i < gN && j < sN)
        {
            if(s[j] >= greed[i])
            {
                ans++;
                i++; 
            }
            j++;
        }

        return ans;
    }
};