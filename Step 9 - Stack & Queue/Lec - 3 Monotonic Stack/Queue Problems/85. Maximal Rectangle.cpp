// Optimal
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        
        vector<int> left(n);
        vector<int> right(n);
        vector<int> area(n);
        stack<pair<int,int>> st;

        for(int i=0; i<n; i++)
        {
            int count = 1;
            while(!st.empty() && st.top().first > heights[i])
            {
                count += st.top().second;
                st.pop();
            }

            left[i] = count;
            st.push({heights[i], count});
        }

        while(!st.empty()) st.pop();

        for(int i=n-1; i>=0; i--)
        {
            int count = 1;
            while(!st.empty() && st.top().first >= heights[i])
            {
                count += st.top().second;
                st.pop();
            }

            right[i] = count;
            st.push({heights[i], count});
        }

        for(int i=0; i<n; i++)
            area[i] = heights[i] * (left[i] + right[i] - 1);
        
        int maxArea = INT_MIN;
        for(int i=0; i<n; i++)
            maxArea = max(maxArea, area[i]);
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxRect = 0;

        vector<int> heights(cols, 0);

        for(int i=rows-1; i>=0; i--)
        {
            for(int j=0; j<cols; j++)
            {
                if(matrix[i][j] == '1') 
                    heights[j] = heights[j] + (matrix[i][j] - '0');
                else heights[j] = 0;
            }

            maxRect = max(maxRect, largestRectangleArea(heights));
        }

        return maxRect;
    }
};



// Solution 1
class Solution {
public:
    vector<int> calculateHeight(vector<vector<char>>& matrix, int row) 
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);

        for (int col = 0; col < cols; col++) 
        {
            if (matrix[row][col] == '0') 
            {
                heights[col] = 0;
                continue;
            }
            
            int current_row = row;
            while (current_row < rows && matrix[current_row][col] == '1')
                current_row++;
            heights[col] = current_row - row;
        }

        return heights;
    }

    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        
        vector<int> left(n);
        vector<int> right(n);
        vector<int> area(n);
        stack<pair<int,int>> st;

        for(int i=0; i<n; i++)
        {
            int count = 1;
            while(!st.empty() && st.top().first > heights[i])
            {
                count += st.top().second;
                st.pop();
            }

            left[i] = count;
            st.push({heights[i], count});
        }

        while(!st.empty()) st.pop();

        for(int i=n-1; i>=0; i--)
        {
            int count = 1;
            while(!st.empty() && st.top().first >= heights[i])
            {
                count += st.top().second;
                st.pop();
            }

            right[i] = count;
            st.push({heights[i], count});
        }

        for(int i=0; i<n; i++)
            area[i] = heights[i] * (left[i] + right[i] - 1);
        
        int maxArea = INT_MIN;
        for(int i=0; i<n; i++)
            maxArea = max(maxArea, area[i]);
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int maxRect = 0;

        for(int i=0; i<rows; i++)
        {
            vector<int> heights = calculateHeight(matrix, i);
            maxRect = max(maxRect, largestRectangleArea(heights));
        }

        return maxRect;
    }
};