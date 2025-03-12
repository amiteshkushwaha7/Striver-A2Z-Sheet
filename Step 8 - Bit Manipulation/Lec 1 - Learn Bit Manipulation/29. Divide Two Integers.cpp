class Solution {
    public:
        int divide(int dividend, int divisor) {
            if (divisor == 0)
                return (dividend > 0) ? INT_MAX : INT_MIN;
            if (dividend == 0) return 0;
            if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    
            long long dvd = abs((long long)dividend);
            long long dvs = abs((long long)divisor);
            int sign = ((dividend > 0) ^ (divisor > 0)) ? -1 : 1;
            long long rem = 0;
    
            while (dvd >= dvs) 
            {
                long long i = 0;
                long long val = dvs;
    
                while (dvd >= (val << 1)) 
                {
                    val <<= 1;
                    i++;
                }
    
                rem += (1LL << i);  
                dvd -= val;
            }
    
            return (sign * rem);
        }
    };