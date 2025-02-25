class Solution {
public:
    double calculatePower(double num, int n)
    {
        if(n == 0) return 1;
        if(n == 1) return num;

        double res = calculatePower(num, n / 2);
        res = res * res;
 
        if(n % 2 != 0) res = res * num;

        return res;
    }

    double myPow(double x, int n) 
    {
        if(n == 0) return 1;
        if (n == INT_MIN) return 1.0 / calculatePower(x, INT_MAX) * 1.0 / x;
        
        
        if(n < 0) return 1.0 / calculatePower(x, -n);
        return calculatePower(x, n);
    }
};