//Brute Force
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int n = arr.size();
        if(k < arr[0]) return k;

        int cntElm = 0;
        int i;
        for(i=0; i<n; i++)
        {
            cntElm = arr[i] - 1 - i;
            if(cntElm >= k)
            {
                int cntElmAtRight = arr[i-1] - 1 - (i-1);
                return arr[i-1] + (k - cntElmAtRight);
            }
        }   
 
        int cntElmAtRight = arr[i-1] - 1 - (i-1);
        return arr[i-1] + (k - cntElmAtRight);
    }
};



//Optimal
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int n = arr.size();
        
        int left = 0, right = n-1;
        int cntElm = 0, mid = 0;
        while(left <= right)
        {
            mid = (left + right)/2;
            cntElm = arr[mid] - 1 - mid;
 
            if(cntElm < k) left = mid + 1;
            else right = mid - 1;
        }

        if (left == 0) return k; 

        int cntElmAtRight = arr[right] - 1 - right; 
        return arr[right] + (k - cntElmAtRight);
    }
};