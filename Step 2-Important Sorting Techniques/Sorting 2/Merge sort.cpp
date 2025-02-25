class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        int size = r-l+1;
        vector<int> tempArr(size);
        
        int i=l, j=m+1, k=0;
        while(i<=m && j<=r)
        {
            if(arr[i] < arr[j]) tempArr[k++] = arr[i++];
            else if(arr[i] > arr[j]) tempArr[k++] = arr[j++];
            else
            {
               tempArr[k++] = arr[i++];
               tempArr[k++] = arr[j++];
            }
        }
        
        while(i<=m) tempArr[k++] = arr[i++];
        while(j<=r) tempArr[k++] = arr[j++];
        
        for(i=0; i<tempArr.size(); i++) arr[l+i] = tempArr[i];
    }
    
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r) return;
        int mid = l+(r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        
        merge(arr, l, mid, r);
    }
};