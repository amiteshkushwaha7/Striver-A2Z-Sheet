class MyStack {
    private:
        queue<int> qu;
    
    public:
        MyStack() {
            
        }
        
        void push(int x) {
            qu.push(x);
        }
        
        int pop() {
            if(qu.size() == 0) 
                return -1;
    
            int val = qu.back();
    
            queue<int> temp;
            while(qu.size() > 1)
            {
                temp.push(qu.front());
                qu.pop();
            }
    
            qu = temp;
            return val;
        }
        
        int top() {
            if(qu.size() == 0) 
                return -1;
            return qu.back();
        }
        
        bool empty() {
            if(qu.size() == 0) 
                return true;
            return false;
        }
    };
    
    /**
     * Your MyStack object will be instantiated and called as such:
     * MyStack* obj = new MyStack();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->top();
     * bool param_4 = obj->empty();
     */