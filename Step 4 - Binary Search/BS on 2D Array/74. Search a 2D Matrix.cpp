//Optimal
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int row = matrix.size();
        int col = matrix[0].size();

        int left = 0, right = row * col - 1;
        while(left <= right)
        {
            int mid = (left + right)/2;

            int r = mid / col;
            int c = mid % col;

            if(matrix[r][c] == target) return true;
            else if(matrix[r][c] > target) right = mid - 1;
            else left = mid + 1;
        }

        return false;
    }
};


//Better 1
class Solution {
public:
    bool binarySearch(vector<int>&arr, int target)
    {
        int left = 0, right = arr.size()-1;
        while(left <= right)
        {
            int mid = (left + right)/2;

            if(arr[mid] == target) return true;
            else if(target > arr[mid]) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int row = matrix.size();
        int col = matrix[0].size();

        bool res = false;
        for(int i=0; i<matrix.size(); i++)
        {
            int left = 0, right = col-1;
            if(target >= matrix[i][0] && target <= matrix[i][col-1])
                res = binarySearch(matrix[i], target);
            if(res) return res;
        }
        return res;
    }
};


//Better 2
class Solution {
public:
    bool binarySearch(vector<int>&arr, int target)
    {
        int left = 0, right = arr.size()-1;
        while(left <= right)
        {
            int mid = (left + right)/2;

            if(arr[mid] == target) return true;
            else if(target > arr[mid]) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        bool res = false;
        for(int i=0; i<matrix.size(); i++)
        {
            res = binarySearch(matrix[i], target);
            if(res) return res;
        }
        return res;
    }
};


//Brute Force
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
                if(target == matrix[i][j]) return true;
        }    
        return false;
    }
};