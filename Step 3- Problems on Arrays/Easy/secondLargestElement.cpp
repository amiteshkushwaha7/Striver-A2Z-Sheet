class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        auto largest = arr.begin();
        for(auto i=largest+1; i!=arr.end(); i++)
            if(*i > *largest) largest = i;
        
        int secondLargest = INT_MIN;
        for(auto i=arr.begin(); i!=arr.end(); i++)
            if(*i > secondLargest && *i < *largest) secondLargest = *i;
        
        if(secondLargest == INT_MIN) return -1;
        return secondLargest;
    }
};