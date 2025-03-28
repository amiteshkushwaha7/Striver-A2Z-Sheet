class Solution {
public:
    string largestOddNumber(string num) 
    {
        
        int n = num.size();
        int lastOddIndex = -1; 
 
        for (int i = 0; i < n; i++) 
        {
            int digit = num[i] - '0';
            if (digit % 2 == 1) lastOddIndex = i;
        } 

        if (lastOddIndex == -1) return "";
        return num.substr(0, lastOddIndex + 1);
    }
};
