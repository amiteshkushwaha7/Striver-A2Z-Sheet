

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) 
    {
        int n = arr.size();
        
        vector<int> vec;
        int leader = arr[n-1];
        vec.push_back(leader);
        
        for(int i=n-2; i>=0; i--)
        {
            if(arr[i] >= leader)
            {
                leader = arr[i];
                vec.push_back(leader);
            }
        }
        
        int i = 0, j = vec.size()-1;
        while(i<j) swap(vec[i++], vec[j--]);
        
        return vec;
    }
};