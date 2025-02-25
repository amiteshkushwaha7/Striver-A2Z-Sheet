class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> vec;
        int i=0, j=0;
        while(i<n && j<m)
        {
            if(arr1[i] < arr2[j]) 
            {
                vec.push_back(arr1[i]);
                int n1 = arr1[i];
                while(arr1[i] == n1) i++;
            }
            else if(arr1[i] > arr2[j])
            {
                vec.push_back(arr2[j]);
                int n2 = arr2[j];
                while(arr2[j] == n2) j++;
            }
            else
            {
                vec.push_back(arr1[i]);
                int n1 = arr1[i];
                int n2 = arr2[j];
                while(arr1[i] == n1) i++;
                while(arr2[j] == n2) j++;
            }
        }
        
        while(i<n)
        {
            vec.push_back(arr1[i]);
            int n1 = arr1[i];
            while(arr1[i] == n1) i++;
        }
        
        while(j<m)
        {
            vec.push_back(arr2[j]);
            int n2 = arr2[j];
            while(arr2[j] == n2) j++;
        }
    
        return vec;
    }
};