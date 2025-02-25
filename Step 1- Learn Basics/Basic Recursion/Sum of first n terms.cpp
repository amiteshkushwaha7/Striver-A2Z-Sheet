class Solution {
  public:
    long long sumOfSeries(long long n) {
        if(n==1)
            return n;
        
        return ((n*n*n) + sumOfSeries(n-1));
    }
};