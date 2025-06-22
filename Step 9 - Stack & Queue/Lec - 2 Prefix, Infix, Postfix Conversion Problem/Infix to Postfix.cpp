// Optimal

class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string& s) 
    {
        map<char,int> precedence;
        precedence['^'] = 3;
        precedence['*'] = 2;
        precedence['/'] = 2;
        precedence['+'] = 1;
        precedence['-'] = 1;
    
        stack<char> st;
        string ans = "";
        
        for(int i=0; i<s.size(); i++)
        {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
                ans += s[i];
            else if(s[i] == '(') st.push(s[i]);
            else if(s[i] == ')')
            {
                while(!st.empty() && st.top() != '(')
                {
                    if(st.top() != '(' && st.top() != ')')
                        ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else 
            {
                while(!st.empty() && st.top() != '(' && precedence[s[i]] <= precedence[st.top()])
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};


