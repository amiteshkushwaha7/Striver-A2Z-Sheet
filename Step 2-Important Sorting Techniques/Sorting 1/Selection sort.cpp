class Solution
{
    public:
    int select(int arr[], int ind, int n)
    {
        for(int j=ind+1; j<n; j++)
        {
            if(arr[j] < arr[ind])
                ind = j;
        }
        return ind;
    }

    void selectionSort(int arr[], int n)
    {
        for(int i=0; i<n; i++)
        {
            int ind = select(arr, i, n);
            swap(arr[ind], arr[i]);
        }
    }
};