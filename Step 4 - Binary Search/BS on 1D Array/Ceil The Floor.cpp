// User code template

class Solution {
  public:
  
    vector<int> getFloorAndCeil(int x, vector<int> &arr) 
    {
        int n = arr.size();
        int largest = INT_MIN, smallest = INT_MAX;
        for(int i=0; i<n; i++)
        {
            if(arr[i] > largest && arr[i] <= x) largest = arr[i];
            if(arr[i] < smallest && arr[i] >= x) smallest = arr[i];
        }
        
        if(largest == INT_MIN) return {-1, smallest};
        else if(smallest == INT_MAX) return {largest, -1};
        return {largest, smallest};
    }
};