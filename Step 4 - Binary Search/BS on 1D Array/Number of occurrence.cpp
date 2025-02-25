class Solution {
  public:
    int findLeft(vector<int>&arr, int target)
    {
        int left = 0, right = arr.size()-1;
        int result = 0;
        
        while(left <= right)
        {
            int mid = (left+right)/2;
            
            if(arr[mid] == target)
            {result = mid; right = mid-1;}
            else if(target > arr[mid]) left = mid+1;
            else right = mid - 1;
        }
        
        return result;
    }
    
    int findRight(vector<int>&arr, int target)
    {
        int left = 0, right = arr.size()-1;
        int result = -1;
        
        while(left <= right)
        {
            int mid = (left + right)/2;
            
            if(arr[mid] == target)
            {result = mid; left = mid+1;}
            else if(target > arr[mid]) left = mid+1;
            else right = mid-1;
        }
        
        return result;
    }
    
    int countFreq(vector<int>& arr, int target) 
    {
        int first_indx = findLeft(arr, target);
        int last_indx = findRight(arr, target);
        
        return last_indx - first_indx + 1;
    }
};
