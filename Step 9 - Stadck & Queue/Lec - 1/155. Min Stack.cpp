class MinStack {
    private:
        stack<long long> st;  
        long long min;   
    
    public:
        MinStack() {
            
        }
        
        void push(int val) {
            if (st.empty()) 
            {
                st.push(val);
                min = val;
            } 
            else if (val < min) 
            { 
                st.push(2LL * val - min);
                min = val;  
            } 
            else st.push(val);
        }
        
        void pop() 
        {
            if (st.empty()) return;  
            
            if (st.top() < min) 
                min = 2LL * min - st.top();
            st.pop();  
        }
        
        int top() {
            if (st.empty()) return -1; 
            
            if (st.top() < min)
                return min;
            return st.top();
        }
        
        int getMin() {
            if (st.empty()) return -1;  
            
            return min;
        }
    };