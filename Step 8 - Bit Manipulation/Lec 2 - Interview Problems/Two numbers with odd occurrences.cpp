class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int n)  
    {
        long long int res = 0;
        for(long long int i = 0; i < n; i++)
            res = res ^ arr[i];
     
        long long int setBit = res & -res;   
        
        long long int num1 = 0, num2 = 0;
        for(long long int i = 0; i < n; i++)
        {
            if (arr[i] & setBit)
                num1 ^= arr[i]; 
            else
                num2 ^= arr[i];  
        }
     
        if (num1 < num2) 
            swap(num1, num2);
        return {num1, num2};
    }
};