class Solution {
  public:
    void printGfg(int N) {
        if(N==1)
        {
            cout<<"GFG"<<" ";
            return;
        }
        
        cout<<"GFG"<<" ";
        printGfg(N-1);
    }
};