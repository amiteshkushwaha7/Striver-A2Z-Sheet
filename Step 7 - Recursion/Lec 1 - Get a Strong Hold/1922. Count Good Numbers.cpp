class Solution {
public:
    const int MOD = 1e9 + 7;

    double calculatePower(long long num, long long n)
    {
        if(n == 0) return 1;
        if(n == 1) return num % MOD;

        long long res = calculatePower(num, n / 2);
        res = (res * res) % MOD;   

        if(n % 2 != 0) res = (res * num) % MOD;

        return res;
    }

    int countGoodNumbers(long long n) 
    {
        long long oddP = n / 2;
        long long evenP = n - oddP;

        long long evenPower = calculatePower(5, evenP);
        long long oddPower = calculatePower(4, oddP);

        return (evenPower * oddPower) % MOD;
    }
};