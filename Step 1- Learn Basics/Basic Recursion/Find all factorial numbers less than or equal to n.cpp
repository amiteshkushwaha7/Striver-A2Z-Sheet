class Solution {
  public:
    vector<long long> factorialNumbers(long long n) {
        vector<long long> vec;
        long long factorial = 1;
        
        for(long long i=1; i<=n; i++)
        {
            if(factorial*i > n) return vec;
            else
            {
                vec.push_back(factorial*i);
                factorial = factorial*i;
            }
        }
    }
};