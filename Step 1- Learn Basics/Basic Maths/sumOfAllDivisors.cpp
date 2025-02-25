// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        long long sum = 0;
        for(int i=1; i<=N; i++)
            sum = sum + (N/i)*i;
        
        return sum;
    }
};