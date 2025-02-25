//Optimal
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        map<int,int> mpp;
        
        int length = 0;
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            sum = sum + arr[i];
            
            if(mpp.find(sum) == mpp.end())
                mpp[sum] = i;
            
            if(sum == 0)
                length = max(length, i+1);
            
            if(mpp.find(sum) != mpp.end())
                length = max(length , i-mpp[sum]);
        }
        
        return length;
    }
};




//Brute Force
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        map<int,int> mpp;
        
        int length = 0;
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            int sum = 0;
            for(int j=i; j<n; j++)
            {
                sum = sum + arr[j];
                if(sum == 0)
                    length = max(length, j-i+1);
            }
        }
        
        return length;
    }
};