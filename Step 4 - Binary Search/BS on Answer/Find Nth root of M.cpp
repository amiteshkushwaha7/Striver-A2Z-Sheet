class Solution{
	public:
	long long power(int mid, int n, int m)
	{
	    long long ans = 1;
	    for(int i=1; i<=n; i++)
	    {
	       ans = ans * mid;
	       if(ans > m) return 2;
	    }
	    if(ans == m) return 1;
	    return 0;
	}
	
	int NthRoot(int n, int m)
	{
	    int left = 1, right = m;
	    int ans = -1;
	    
	    while(left <= right)
	    {
	        int mid = (left + right)/2;
	        long long p = power(mid, n, m);
	        
	        if(p == 1) return mid;
	        else if(p == 0) left = mid + 1;
	        else right = mid - 1;
	    }
	    
	    return -1;
	}  
};