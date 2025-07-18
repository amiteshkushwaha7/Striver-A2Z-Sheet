class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();

        int minimum = 0;
        int maximum = 0;

        for(int i=0; i<n; i++)
        {
            if(s[i] == '(')
            {
                minimum++;
                maximum++;
            }
            else if(s[i] == ')')
            {
                minimum--;
                maximum--;
            }
            else 
            {
                minimum--;
                maximum++;
            }

            if(minimum < 0)
                minimum = 0;
            
            if(maximum < 0)
                return false;
        }

        return minimum == 0;
    }
};