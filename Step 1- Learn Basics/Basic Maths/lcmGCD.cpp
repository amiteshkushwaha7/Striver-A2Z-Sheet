// } Driver Code Ends
class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        long long num1 = A;
        long long num2 = B;
        
        long long lcm;
        long long gcd;
        
        while(num1>0 && num2>0)
        {
            if(num1 > num2) num1 = num1 % num2;
            else num2 = num2 % num1;
        }
            
        if(num1 == 0) gcd = num2;
        else gcd = num1;
        
        lcm = (A*B)/gcd;
        
        vector<long long> vec;
        vec.push_back(lcm);
        vec.push_back(gcd);
        return vec;
    }
};