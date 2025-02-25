class Solution {
public:
    void generateWords(map<char,string> &mpp, string &digits, int digitsIndx, string word, vector<string> &ans)
    {
        if (digits.empty()) return;
        if(digitsIndx == digits.size())
        {
            ans.push_back(word);
            return;
        }

        string str = mpp[digits[digitsIndx]];
        for (char ch : str) 
            generateWords(mpp, digits, digitsIndx + 1, word + ch, ans);
    }

    vector<string> letterCombinations(string digits) 
    {
        map<char, string> mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8']= "tuv";
        mpp['9'] = "wxyz";

        vector<string> ans;
        generateWords(mpp, digits, 0, "", ans);
        return ans;
    }
};