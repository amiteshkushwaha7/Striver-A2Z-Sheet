//Optimal
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRowHasZero = false, firstColHasZero = false;
        for(int i=0; i<n; i++)
        {
            if(matrix[0][i] == 0)
            {firstRowHasZero = true; break;}
        }

        for(int i=0; i<m; i++)
        {
            if(matrix[i][0] == 0)
            {firstColHasZero = true; break;}
        }
         

        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;   
                }
            }
        }

        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
        }

        if(firstRowHasZero == true)
        {
            for(int i=0; i<n; i++)
                matrix[0][i] = 0;
        }

        if(firstColHasZero == true)
        {
            for(int i=0; i<m; i++)
                matrix[i][0] = 0;
        }
    }
};



//Brute Force
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        vector<pair<int,int>> vec;

        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
                if(matrix[i][j] == 0) vec.push_back({i,j});
        }

        for(int i=0; i<vec.size(); i++)
        {
            int row = vec[i].first;
            int col = vec[i].second;

            for (int k=0; k<n; k++) 
                matrix[row][k] = 0;
            for (int k=0; k<m; k++) 
                matrix[k][col] = 0;
        }
    }
};