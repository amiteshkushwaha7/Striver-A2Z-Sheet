class Solution {
public:
    int jump(vector<int>& arr) {
        int n = arr.size();

        if(n == 1)
            return 0; 
        if(n == 2 || arr[0] >= n-1)
            return 1;    

        int i = 0;
        int ans = 0;
        while(i < n)
        {
            int jumps = 0;
            int j = i+1;
            int indx = j;

            while(j <= arr[i] + i)
            {
                if(jumps >= n-1 || j >= n-1)
                    return ans+2;
                
                if(arr[j] + j >= jumps)
                {
                    jumps = arr[j] + j;
                    indx = j;
                }

                j++;
            }

            if(jumps >= n-1 || j >= n-1)
                return ans+2;

            i = indx;
            ans++;
        }

        return ans;
    }
};