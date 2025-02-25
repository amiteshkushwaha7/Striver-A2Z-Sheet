//Optimal
class Solution {
public:
    int maxIndx(vector<vector<int>> &arr, int row, int col) {
        int maxVal = -1, indx = 0;
        for (int i = 0; i < row; i++) 
        {
            if (arr[i][col] > maxVal) 
            {
                maxVal = arr[i][col];
                indx = i;
            }
        }
        return indx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        int low = 0, high = col - 1;
        while (low <= high) 
        {
            int mid = (low + high) / 2;
            int maxRowIndx = maxIndx(mat, row, mid);
 
            int left = (mid - 1 >= 0) ? mat[maxRowIndx][mid - 1] : -1;
            int right = (mid + 1 < col) ? mat[maxRowIndx][mid + 1] : -1;
 
            if (mat[maxRowIndx][mid] > left && mat[maxRowIndx][mid] > right)
                return {maxRowIndx, mid};
 
            else if (left > mat[maxRowIndx][mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return {-1, -1};
    }
};


//Brute Force
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) 
    {   
        int row = mat.size();
        int col = mat[0].size();

        int fIndx = 0, lIndx = 0;
        for(int i=0; i<col; i++)
        {
            if(mat[0][i] > mat[0][fIndx]) fIndx = i;
            if(mat[row-1][i] > mat[row-1][lIndx]) lIndx = i;  
        }

        if(row > 1)
        {
            if(mat[0][fIndx] > mat[1][fIndx]) return {0,fIndx};
            if(mat[row-1][lIndx] > mat[row-2][lIndx]) return {row-1, lIndx};
        }
        return {0, fIndx};

        for(int i=1; i<row-2; i++)
        {
            int peakIndx = 0;
            for(int j=0; j<col; j++)
            {
                if(mat[i][j] > mat[i][peakIndx])
                    peakIndx = j;
            }

            if(mat[i][peakIndx] > mat[i-1][peakIndx] && mat[i][peakIndx] > mat[i+1][peakIndx]) 
                return {i, peakIndx};
        }

        return {-1, -1};
    }
};