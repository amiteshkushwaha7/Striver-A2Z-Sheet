class Solution {
  public:
    void printNos(int N) {
        if(N==1)
        {
            cout<<N<<" ";
            return;
        }
        
        cout<<N<<" ";
        printNos(N-1);
    }
};