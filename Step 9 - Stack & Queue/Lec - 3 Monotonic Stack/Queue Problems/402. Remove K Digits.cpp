//Optimal
class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        int n = num.size();
        if (k == n) return "0";

        string result;

        for (char c : num)
        {
            while (k > 0 && !result.empty() && result.back() > c)
            {
                result.pop_back();
                k--;
            }
            result.push_back(c);
        }

        while (k > 0 && !result.empty()) {
            result.pop_back();
            k--;
        }

        int i = 0;
        while (i < result.size() && result[i] == '0') i++;

        result = result.substr(i);
        return result.empty() ? "0" : result;
    }
};
