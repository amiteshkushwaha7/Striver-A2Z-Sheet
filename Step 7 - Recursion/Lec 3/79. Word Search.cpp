class Solution {
    public:
        void searchWord(vector<vector<char>>& board, string word, int indx, int r, int c, bool &ans)
        {
            if(indx >= word.size()) { ans = true; return; } 
            if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || ans) 
                return;  
    
            if(board[r][c] == word[indx])
            {
                char letter = board[r][c];
                board[r][c] = '1';
                
                searchWord(board, word, indx+1, r, c-1, ans); 
                searchWord(board, word, indx+1, r, c+1, ans); 
                searchWord(board, word, indx+1, r-1, c, ans); 
                searchWord(board, word, indx+1, r+1, c, ans); 
                
                board[r][c] = letter;
            }       
        }
    
        bool exist(vector<vector<char>>& board, string word) 
        {  
            int row = board.size();
            int col = board[0].size();
            bool ans = false;
    
            for(int i = 0; i < row; i++)
            {
                for(int j = 0; j < col; j++)
                {
                    if(board[i][j] == word[0])
                    {
                        searchWord(board, word, 0, i, j, ans);
                        if(ans) return true;
                    }
                }
            }
            return ans;
        }
    };