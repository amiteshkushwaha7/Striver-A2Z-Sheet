// User function Template for C++

class Solution {
  public:
    void heapify(vector<int>&arr, int n, int indx)
    {
        int left = 2 * indx + 1;
        int right = 2 * indx + 2;
        
        int largest = indx;
        
        if(left < n && arr[left] > arr[largest])
            largest = left;
        if(right < n && arr[right] > arr[largest])
            largest = right;
            
        if(largest != indx)
        {
            swap(arr[largest], arr[indx]);
            heapify(arr, n, largest);
        }
    }
    
    void convertMinToMaxHeap(vector<int> &arr, int n) {
        for(int i=n/2; i>=0; i--)
            heapify(arr, n, i);
    }
};
