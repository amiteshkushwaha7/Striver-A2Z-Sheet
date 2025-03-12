// User function template for C++

class Solution {
    public:
      void generatePath(vector<vector<int>> &mat, int r, int c, string path, vector<string> &ans)
      {
          int n = mat.size();
          
          if (r == n - 1 && c == n - 1)   
          {
              ans.push_back(path);
              return;
          }
  
          if (r < 0 || r >= n || c < 0 || c >= n || mat[r][c] == 0) 
              return;
              
          int digit = mat[r][c];
          mat[r][c] = 0;
  
          generatePath(mat, r, c - 1, path + 'L', ans);
          generatePath(mat, r, c + 1, path + 'R', ans);
          generatePath(mat, r - 1, c, path + 'U', ans);
          generatePath(mat, r + 1, c, path + 'D', ans);
  
          mat[r][c] = digit;
      }
      
      vector<string> findPath(vector<vector<int>> &mat) 
      {
          int n = mat.size();
          vector<string> ans;
          if (mat.empty() || mat[0][0] == 0 || mat[n-1][n-1] == 0)
              return ans;
  
          string path = "";
          
          generatePath(mat, 0, 0, path, ans);
  
          return ans;
      }
  };