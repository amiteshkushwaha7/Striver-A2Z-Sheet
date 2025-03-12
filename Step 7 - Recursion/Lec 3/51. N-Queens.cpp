class Solution {
    public:
        bool isValid(vector<string> &board, int r, int c) 
        {
            int n = board.size();
            int j = c + r;
            int l = c - r;
    
            for (int i = 0; i < n; i++) 
            {
                if (board[r][i] == 'Q') return false;
                if (board[i][c] == 'Q') return false;
    
                if (j - i >= 0 && j - i < n && board[i][j - i] == 'Q') return false;
                if (l + i >= 0 && l + i < n && board[i][l + i] == 'Q') return false;
            }
    
            return true;
        }
    
        void placeQueens(vector<vector<string>> &ans, vector<string> &board, int r, int n) 
        {
            if(r == n) 
            {
                ans.push_back(board);
                return;
            }
    
            for (int c = 0; c < board.size(); c++) 
            {
                if (isValid(board, r, c)) 
                {
                    board[r][c] = 'Q';
            
                    placeQueens(ans, board, r+1, n);
                        
                    board[r][c] = '.';
                }
            }
        }
    
        vector<vector<string>> solveNQueens(int n) 
        {
            vector<vector<string>> ans;
            vector<string> empty(n, string(n, '.'));   
    
            placeQueens(ans, empty, 0, n);
            return ans;
        }
    };