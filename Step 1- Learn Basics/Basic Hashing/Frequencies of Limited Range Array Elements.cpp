class Solution {
  public:
    // Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr, int N, int P) {
        vector<int> frequency(N, 0);
        for(int i=0; i<N; i++)
            if(arr[i] <= N) frequency[arr[i]-1]++;
            
        for(int i=0; i<N; i++)
            arr[i] = frequency[i];
    }
};