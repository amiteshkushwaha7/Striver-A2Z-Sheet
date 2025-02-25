class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n) {
        // Your code here
        for(int j=1; j<n; j++)
        {
            for(int i=0; i<n-j; i++)
            {
                if(arr[i] > arr[i+1])
                    swap(&arr[i], &arr[i+1]);
            }
        }
    }
};