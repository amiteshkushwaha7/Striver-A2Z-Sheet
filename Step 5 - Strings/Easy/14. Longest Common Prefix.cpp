class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string ans = "";
        int row = strs.size();
        if(row == 0 || row == 1) 
            return strs[0];
            
        int col = INT_MAX;
        for (int i = 0; i < row; i++) 
            col = min(col, static_cast<int>(strs[i].size()));
        
        for(int i=0; i<col; i++)
        {
            char c = strs[0][i];
            int j;
            for(j=1; j<row; j++)
            {
                if(strs[j][i] != c) 
                    break;
            }

            if(j == row) ans += c;
            else break;                 
        }
        return ans;
    }
};