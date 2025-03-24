class Solution {
    public:
        bool isValid(string s) {
            if(s.size() == 0)
                return false;
    
            stack<char> st;
    
            for(int i=0; i < s.size(); i++)
            {
                if(st.empty())
                {
                    st.push(s[i]);
                    continue;
                }
    
                if(st.top() == '(' && s[i] == ')')
                    st.pop();
                else if(st.top() == '{' && s[i] == '}')
                    st.pop();
                else if(st.top() == '[' && s[i] == ']')
                    st.pop();
                else st.push(s[i]);
            }
    
            if(st.empty())
                return true;
            return false;
        }
    };