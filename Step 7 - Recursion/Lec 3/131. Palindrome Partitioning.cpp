class Solution {
    public:
        bool isPalindrome(string str)
        {
            int i = 0, j = str.size() - 1;
            while (i < j)
            {
                if (str[i] != str[j]) 
                    return false;
                i++;
                j--;
            }
            return true;
        }
    
        void partitionHelper(string s, vector<string> &partition, vector<vector<string>> &ans)
        {
            if (s.empty()) 
            {
                ans.push_back(partition);
                return;
            }
    
            for (int i = 0; i < s.size(); i++)
            {
                string part = s.substr(0, i + 1);
                
                if (isPalindrome(part))  
                {
                    partition.push_back(part);
    
                    partitionHelper(s.substr(i + 1), partition, ans); 
    
                    partition.pop_back();   
                }
            }
        }
    
        vector<vector<string>> partition(string s) 
        {    
            vector<vector<string>> ans;
            vector<string> partition;  
    
            partitionHelper(s, partition, ans);
            return ans;
        }
    };