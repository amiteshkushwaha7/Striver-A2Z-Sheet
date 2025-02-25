class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> vec;
        int rows = matrix.size();
        int cols = matrix[0].size();

        int startRow = 0, endRow = rows-1;
        int startCol = 0, endCol = cols-1;

        while(startRow <= endRow && startCol <= endCol) 
        {
            for(int i=startCol; i<=endCol; i++)
                vec.push_back(matrix[startRow][i]);
            startRow++;

            for(int i=startRow; i<=endRow; i++)
                vec.push_back(matrix[i][endCol]);
            endCol--;
            
            if(startRow <= endRow)
            {
                for(int i=endCol; i>=startCol; i--)
                    vec.push_back(matrix[endRow][i]);
                endRow--;
            }

            if(startCol <= endCol)
            {
                for(int i=endRow; i>=startRow; i--)
                    vec.push_back(matrix[i][startCol]);
                startCol++;
            }
        }

        return vec;
    }
};
