//User function Template for C++

class Solution{
public:
    void generateStrings(string str, vector<string> &ans, int n)
    {
        if(str.length() == n)
        {
            ans.push_back(str);
            return;
        }

        if(str.length() == 0 || str[str.length() - 1] == '0')
        {
            generateStrings(str + '0', ans, n);
            generateStrings(str + '1', ans, n);
        }
        else generateStrings(str + '0', ans, n);
    }
    
    vector<string> generateBinaryStrings(int num)
    {
        vector<string> ans;
        generateStrings("", ans, num);
        return ans;
    }
};