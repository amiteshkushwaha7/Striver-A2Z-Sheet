class Solution
{
    public:
    void insert(int arr[], int n, int ind)
    {
        if(ind == n) return;

        int indx = ind;
        for(int i=ind-1; i>=0; i--)
        {
            if(arr[i] > arr[ind])
            {
                int k = arr[i];
                arr[i] = arr[ind];
                arr[ind] = k;
                ind--;
            }
            else break;
        }
        
        insert(arr, n, indx+1);
    }
    
    public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        insert(arr, n, 0);
    }
};