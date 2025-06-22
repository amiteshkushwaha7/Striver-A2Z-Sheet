//Optimal
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
};