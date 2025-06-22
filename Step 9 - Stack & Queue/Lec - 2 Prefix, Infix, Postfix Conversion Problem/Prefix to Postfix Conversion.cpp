// User function Template for C++

class Solution {
  public:
    string preToPost(string s) {
        stack<string> st;
        for(int i=s.size()-1; i>=0; i--)
        {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
                st.push(string(1, s[i]));
            else if(s[i] == '^' || s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-')
            {
                string temp = "";
                string temp1 = st.top(); st.pop();
                string temp2 = st.top(); st.pop();
                
                temp = temp1 + temp2 + s[i];
                st.push(temp);
            }
        }
        return st.top();
    }
};