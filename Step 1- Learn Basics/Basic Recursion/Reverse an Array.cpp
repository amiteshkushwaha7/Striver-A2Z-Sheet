class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        reverse(arr, 0, arr.size()-1);
    }
    
    void reverse(vector<int> &arr, int start, int end)
    {
        if(start >= end) return;
        
        swap(arr[start], arr[end]);
        reverse(arr, start+1, end-1);
    }
};