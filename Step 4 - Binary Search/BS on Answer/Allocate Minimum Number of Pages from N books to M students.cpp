class Solution {
  public:
    bool isPossible(vector<int> &arr, int mid, int student)
    {
        int cntStudent = 1;
        int cntPages = 0;
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i] > mid) return false;
            
            if(cntPages + arr[i] <= mid)
                cntPages += arr[i];
            else
            {
                cntStudent++;
                cntPages = arr[i];
            }
        }
        
        if(cntStudent > student) return false;
        return true;
    }
  
    int findPages(vector<int> &arr, int k) 
    {
        int n = arr.size();
        if(k > n) return -1;
        
        int ans = -1;
        int low = 0, high = 0;
        for(int i=0; i<n; i++) high += arr[i];
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            if(isPossible(arr, mid, k))
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};