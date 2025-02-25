class Solution {
  public:
  
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searched
    int searchInSorted(int arr[], int N, int K) {
        return binarySearch(arr, 0, N-1, K);
    }
    
    int binarySearch(int arr[], int low, int high, int k)
    {
        if(high<low) return -1;
        
        int mid = (low+high)/2;
        
        if(arr[mid] == k) return 1;
        else if(k > arr[mid]) binarySearch(arr, mid+1, high, k);
        else binarySearch(arr, low, mid-1, k);
    }
};