class Solution {
    public:
        double myPow(double x, int n) 
        { 
            if (n == 0) return 1.0;
    
            if (x == 0) 
            {
                if (n < 0)
                    return NAN;
                return 0.0;
            }
    
            long long N = n; 
            if (N < 0) 
            {
                x = 1 / x;
                N = -N;
            }
    
            double rem = 1.0;
            while (N > 0) 
            {
                if (N % 2 == 1) 
                    rem *= x;
                x = x * x;
                N = N / 2;
            }
    
            return rem;
        }
    };