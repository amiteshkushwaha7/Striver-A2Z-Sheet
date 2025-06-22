//Optimal
class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();

        for (int i = 0; i < n; i++) 
        {
            bool isCelebrity = true;

            for (int j = 0; j < n; j++) 
            {
                if (i == j) continue;

                if (mat[i][j] == 1 || mat[j][i] == 0) 
                {
                    isCelebrity = false;
                    break;
                }
            }

            if (isCelebrity) return i;
        }

        return -1;
    }
};
