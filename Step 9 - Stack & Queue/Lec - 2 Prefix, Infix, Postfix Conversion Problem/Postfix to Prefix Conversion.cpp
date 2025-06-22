// Optimal
// User function Template for C++

class Solution {
  public:
    string postToPre(string s) {
        // Write your code here
        stack<string> st;
        for(int i=0; i<s.size(); i++)
        {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
                st.push(string(1, s[i]));
            else if(s[i] == '^' || s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-')
            {
                string temp = "";
                string temp2 = st.top(); st.pop();
                string temp1 = st.top(); st.pop();
                
                temp = s[i] + temp1 + temp2;
                st.push(temp);
            }
        }
        return st.top();
    }
};