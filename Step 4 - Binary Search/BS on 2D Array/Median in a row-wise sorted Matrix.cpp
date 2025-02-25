//Optimal
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int upperBound(vector<int> &arr, int C, int num) 
    {
        int left = 0, right = C - 1;
        int ans = C;
        while (left <= right) 
        {
            int mid = (left + right) / 2;
    
            if (arr[mid] > num) 
            {
                ans = mid;
                right = mid - 1;
            } 
            else left = mid + 1;
        }
        return ans;
    }
    
    int countLessEquals(vector<vector<int>>& mat, int R, int C, int num) 
    {
        int cnt = 0;
        for (int i = 0; i < R; i++) cnt += upperBound(mat[i], C, num);
        return cnt;
    }
    
    int median(vector<vector<int>> &mat, int R, int C) 
    {
        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < R; i++) 
        {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][C - 1]);
        }
    
        int desiredCnt = (R * C + 1) / 2;  
        while (low < high) 
        {
            int mid = (low + high) / 2;
            int cnt = countLessEquals(mat, R, C, mid);
    
            if(cnt < desiredCnt) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};



//Brute Force
class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<int> vec;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
                vec.push_back(matrix[i][j]);
        }
        
        sort(vec.begin(), vec.end());
        return vec[vec.size()/2];
    }
};