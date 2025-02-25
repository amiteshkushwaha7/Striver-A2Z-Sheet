class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n) {
        if(n==1) return;
        
        int i;
        bool flag = false;
        for(i=0; i<n-1; i++) 
        {
            if(arr[i] > arr[i+1])
            {
                swap(arr[i], arr[i+1]);
                flag = true;
            }
        }
        
        if(flag == false) return;
            
        bubbleSort(arr, i);
    }
    
    
};