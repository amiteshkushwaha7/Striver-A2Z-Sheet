class Solution
{
    public:
    void insert(int arr[], int n, int ind)
    {
        int i=ind-1, elm;
        while(i>=0 && (arr[i] > arr[i+1]))
        {
            elm = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = elm;
            i--;
        }
    }
    
    public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        for(int i=1; i<n; i++)
            if(arr[i] < arr[i-1]) insert(arr, n, i);
    }
};