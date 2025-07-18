class Solution {
public:
    bool canJump(vector<int>& arr) {
        int n = arr.size();

        if(n == 1)
            return true;
        if(n == 2 && arr[0] == 0)
            return false;
        if(n == 2)
            return true;

        int i = 0;
        while(i < n)
        {
            if(arr[i] == 0 && i < n-1)
                return false; 
            int j = i+1;
            int jump = 0, indx = j;

            while(j <= arr[i] + i)
            {
                if(jump >= n-1 || j >= n-1)
                    return true;

                if(arr[j] + j >= jump)
                {
                    jump = arr[j] + j;
                    indx = j;
                }
                
                j++;
            }

            i = indx;
        }

        return false;
    }
};