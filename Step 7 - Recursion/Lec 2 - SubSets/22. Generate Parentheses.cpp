class Solution {
public:
    bool checkParenthesis(string str)
    {
        int cnt = 0;
        for(int i=0; i<str.length(); i++)
        {
            if(str[i] == '(') cnt++;
            else cnt--;

            if(cnt < 0) return false;
        }

        return cnt == 0;
    }
    void generateAllParenthesis(string str, vector<string> &ans, int n, int open, int close)
    {
        if(open > n || close > n) return;
        
        if(str.length() == n*2)
        {
            if(checkParenthesis(str)) ans.push_back(str);
            return;
        }

        generateAllParenthesis(str + '(', ans, n, open + 1, close);
        generateAllParenthesis(str + ')', ans, n, open, close + 1);
    }

    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        generateAllParenthesis("", ans, n, 0, 0);
        return ans;
    }
};