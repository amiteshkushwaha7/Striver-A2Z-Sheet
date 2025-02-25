//Optimal
//User function Template for C++

class Solution{
public:
    void insertAtBottom(stack<int> &st, int Top, int cnt)
    {
        if(st.size() == cnt) 
        {
            st.push(Top);
            return;
        }
        
        int elm = st.top();
        st.pop();
        
        insertAtBottom(st, Top, cnt);
        st.push(elm);
    }

    void Reverse(stack<int> &St)
    {
        int n = St.size();
        if(n == 0 || n == 1) return;
        
        int cnt = 0;
        while(cnt < n)
        {
            int Top = St.top();
            St.pop();
            
            insertAtBottom(St, Top, cnt);
            cnt++;
        }
    }
};


//Brute Force
//User function Template for C++

class Solution{
public:
    void Reverse(stack<int> &st)
    {
        if(st.empty()) return;
        
        stack<int> newSt;
        while(!st.empty())
        {
            newSt.push(st.top());
            st.pop();
        }
        
        st = newSt;
    }
};