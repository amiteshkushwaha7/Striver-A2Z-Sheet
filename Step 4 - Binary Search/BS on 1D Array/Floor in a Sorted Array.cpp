class Solution {
  public:
    int findFloor(vector<int>& arr, int k) 
    {
        int n = arr.size();
        int low = 0, high = n-1, mid;
        while(low <= high)
        {
            mid = (low + high)/2;
            
            if(arr[mid] == k) return mid;
            if(low == high) break;
            
            if(k > arr[mid]) low = mid+1;
            else high = mid-1;
        }
        
        if(k > arr[mid]) return mid;
        return mid-1;
    }
};
