class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        map<int,int> mp;
        int sum = 0, length = 0;
        for(int i=0; i<N; i++)
        {
            sum = sum + A[i];
            if (mp.find(sum) == mp.end())
                mp[sum] = i;
                
            if(sum == K)
                length = max(length, i+1);
            
            if(mp.find(sum - K) != mp.end())
                length = max(length, i-mp[sum-K]   );
        }
        
        return length;
    } 
};