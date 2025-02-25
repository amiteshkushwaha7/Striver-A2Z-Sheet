//Optimal
class Solution {
  public:
    int merge(vector<int> &arr, int start, int mid, int end) 
    {
        vector<int> vec;
        int i = start;
        int j = mid + 1;
        int inversion = 0;
    
        while (i <= mid && j <= end) {
            if (arr[i] <= arr[j]) {
                vec.push_back(arr[i++]);
            } else {
                vec.push_back(arr[j++]);
                inversion += (mid - i + 1);   
            }
        }
    
        while (i <= mid) vec.push_back(arr[i++]);
        while (j <= end) vec.push_back(arr[j++]);
    
        int k = 0;
        for (i = start; i <= end; i++) arr[i] = vec[k++];
    
        return inversion;
    }
    
    int merge_sort(vector<int> &arr, int start, int end) 
    {
        if (start >= end) return 0;
    
        int mid = (start + end) / 2;
        int inversion = 0;
    
        inversion += merge_sort(arr, start, mid);      
        inversion += merge_sort(arr, mid + 1, end);     
        inversion += merge(arr, start, mid, end);       
    
        return inversion;
    }
    
    int inversionCount(vector<int> &arr) 
    {
        return merge_sort(arr, 0, arr.size() - 1);
    }

};





//Brute Force
class Solution {
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) 
    {
        int n = arr.size();
        int count = 0;
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(arr[i] > arr[j]) 
                    count++;
            }
        }
        
        return count;
    }
};