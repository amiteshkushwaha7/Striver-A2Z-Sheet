class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low >= high) return;
        
        if(low < high)
        {
            int pvtInd = partition (arr, low, high);
            quickSort(arr, low, pvtInd-1);
            quickSort(arr, pvtInd+1, high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        int left=low, right=high, pivot=high;
        while(left < right)
        {
            while(arr[left] <= arr[pivot] && left <= high-1) left++;
            while(arr[right] > arr[pivot] && right >= low+1) right--;
            
            if(left < right) swap(arr[left], arr[right]);
        }
        swap(arr[left], arr[pivot]);
        
        return left;
    }
};