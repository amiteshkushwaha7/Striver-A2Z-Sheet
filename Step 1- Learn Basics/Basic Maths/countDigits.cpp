// } Driver Code Ends
class Solution{
public:
    int evenlyDivides(int N){
        int x = N;
        int digit, count=0;
        
        while(x)
        {
            digit = x % 10;
            if(digit > 0 && N % digit == 0) count++;
            x = x/10;
        }
        
        return count;
    }
};
