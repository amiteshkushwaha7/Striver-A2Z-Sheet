class Solution {
    public:
        bool isValid(vector<vector<char>> &board, int r, int c, char digit)
        {
            for(int i=0; i<9; i++)
            {
                if(board[r][i] == digit) return false;  
                if(board[i][c] == digit) return false;  
            }
    
            int boxRow = (r / 3) * 3;
            int boxCol = (c / 3) * 3;
    
            for (int i = 0; i < 3; i++) 
            {
                for (int j = 0; j < 3; j++) 
                    if (board[boxRow + i][boxCol + j] == digit) return false;  
            }
            return true;
        }
    
        void placeDigits(vector<vector<char>> &board, int r, char digit, bool &flag)
        {
            if(flag) return;
            if(r == 9) 
            {
                flag = true;
                return;
            }
    
            for(int c = 0; c < 9; c++)
            {
                if(board[r][c] == '.')
                {
                    for(char d = '1'; d <= '9'; d++)  
                    {
                        if(isValid(board, r, c, d))
                        {
                            board[r][c] = d;
                            placeDigits(board, r, d, flag);
    
                            if(flag) return; 
                            board[r][c] = '.';   
                        }
                    }
                    return;  
                }
            }
            placeDigits(board, r + 1, digit, flag); 
        }
    
        void solveSudoku(vector<vector<char>>& board) 
        {
            bool flag = false;
            placeDigits(board, 0, '1', flag);
        }
    };