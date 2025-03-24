
class MyStack {
    private:
      StackNode *top;
  
    public:
      void push(int x) 
      {
          StackNode *newNode = new StackNode(x);
          
          newNode->next = top;
          top = newNode;
      }
  
      int pop() {
          if(top == NULL) return -1;
          
          int val = top->data;
          
          StackNode *temp = top;
          top = top->next;
          temp->next = NULL;
          delete temp;
          
          return val;
      }
  
      MyStack() { top = NULL; }
  };
  