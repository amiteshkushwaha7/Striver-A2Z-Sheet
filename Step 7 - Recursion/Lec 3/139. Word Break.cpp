class Solution {
    public:
        bool isValid(string s, vector<string> &wordDict) 
        {
            for (int i = 0; i < wordDict.size(); i++)
                if (s == wordDict[i]) return true;
            return false;
        }
    
        bool breakString(string str, vector<string>& wordDict, unordered_map<string, bool>& memo) 
        {
            if (str.empty()) return true;  
    
            if (memo.find(str) != memo.end()) return memo[str];  
    
            for (int i = 0; i < str.size(); i++) 
            {
                string part = str.substr(0, i + 1);
    
                if (isValid(part, wordDict) && breakString(str.substr(i + 1), wordDict, memo)) 
                    return memo[str] = true; 
            }
            return memo[str] = false;   
        }
    
        bool wordBreak(string str, vector<string>& wordDict) 
        {
            unordered_map<string, bool> memo;
            return breakString(str, wordDict, memo);
        }
    };
    