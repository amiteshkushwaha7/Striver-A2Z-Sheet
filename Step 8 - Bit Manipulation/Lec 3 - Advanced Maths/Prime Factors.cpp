class Solution{
	public:
	vector<int> isPrime(int n)
	{
	    
	    vector<int> prime(n+1, 1);
	    prime[0] = prime[1] = 0;
	    for(int i=2; i*i<=n; i++)
	    {
	        if(prime[i])
	        {
	            for(int j=i*i; j<=n; j+=i)
	               prime[j] = 0;
	        }
	    }
	    vector<int> ans;
	    for(int i=0; i<=n; i++)
	    {
	        if(prime[i] && n % i == 0)
	             ans.push_back(i);
	    }
	    return ans;
	}
	vector<int>AllPrimeFactors(int n) 
	{
	    return isPrime(n);
	}
};