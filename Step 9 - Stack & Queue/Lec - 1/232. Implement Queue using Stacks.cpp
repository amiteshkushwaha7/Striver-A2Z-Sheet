class MyQueue {
    private:
        stack<int> inp;
        stack<int> out;
    
    public:
        MyQueue() {
            
        }
        
        void push(int x) {
            inp.push(x);
        }
        
        int pop() 
        {
            if(inp.size() == 0 && out.size() == 0)
                return -1;
            
            if(out.size() == 0)
            {
                while(inp.size())
                {
                    out.push(inp.top());
                    inp.pop();
                }
            }
    
            int val = out.top();
            out.pop();
            return val;
        }
        
        int peek() {
            if(inp.size() == 0 && out.size() == 0)
                return -1;
            
            if(out.size() == 0)
            {
                while(inp.size())
                {
                    out.push(inp.top());
                    inp.pop();
                }
            }
            return out.top();
        }
        
        bool empty() {
            if(inp.size() == 0 && out.size() == 0)
                return true;
            return false;
        }
    };
    
    /**
     * Your MyQueue object will be instantiated and called as such:
     * MyQueue* obj = new MyQueue();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->peek();
     * bool param_4 = obj->empty();
     */