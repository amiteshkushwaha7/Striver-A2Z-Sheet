//Optimal 1
// User function template for C++
class Solution {
  public:
    int findLeft(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, right = n-1;
        int indx = n;
        while(left <= right)
        {
            int mid = (left + right)/2;
            
            if(nums[mid] == 0) left = mid + 1;
            else {indx = mid; right = mid - 1;}
        }
        
        return indx;
    }
    
    int rowWithMax1s(vector<vector<int>> &arr) 
    {
        int row = arr.size();
        int col = arr[0].size();
        int maxOnesRow = -1, maxCntOnes = 0;
        
        for(int i=0; i<row; i++)
        {
            int leftMostIndx = findLeft(arr[i]);
             
            int cntOnes = col - leftMostIndx;
            
            if(cntOnes > maxCntOnes)
            {
                maxCntOnes = cntOnes;
                maxOnesRow = i;
            }
        }
        
        return maxOnesRow;
    }
};



//Optimal 2
class Solution {
  public:
    int findLeft(vector<int> &nums)
    {
        int left = 0, right = nums.size()-1;
        int indx = 0;
        while(left <= right)
        {
            int mid = (left + right)/2;
            
            if(nums[mid] == 0) left = mid + 1;
            else {indx = mid; right = mid - 1;}
        }
        
        return indx;
    }
    
    int findRight(vector<int> &nums)
    {
        int left = 0, right = nums.size()-1;
        int indx = -1;
        while(left <= right)
        {
            int mid = (left + right)/2;
            
            if(nums[mid] == 1) indx = mid;
            left = mid + 1;
        }
        
        return indx;
    }
    
    int rowWithMax1s(vector<vector<int>> &arr) 
    {
        int row = arr.size();
        int col = arr[0].size();
        int maxOnesRow = -1, maxCntOnes = 0;
        
        for(int i=0; i<row; i++)
        {
            int leftMostIndx = findLeft(arr[i]);
            int rightMostIndx = findRight(arr[i]);
            
            int cntOnes = rightMostIndx - leftMostIndx + 1;
            
            if(cntOnes > maxCntOnes)
            {
                maxCntOnes = cntOnes;
                maxOnesRow = i;
            }
        }
        
        return maxOnesRow;
    }
};


//Brute Force
4
cpp	85 / 85	View
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) 
    {
        int row = arr.size();
        int col = arr[0].size();
        int maxOnesRow = -1, maxCntOnes = 0;
        for(int i=0; i<row; i++)
        {
            int cntOnes = 0;
            for(int j=0; j<col; j++)
                if(arr[i][j] == 1) cntOnes++;
            
            if(cntOnes > maxCntOnes)
            {maxOnesRow = i; maxCntOnes = cntOnes;}
        }
        return maxOnesRow;
    }
};