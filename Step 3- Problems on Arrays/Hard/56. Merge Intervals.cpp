class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> vec;
        int n = intervals.size();
        int i = 0, j = 0;
        while(i<n)
        {
            if(vec.empty())
            {
                vec.push_back(intervals[i]);
                i++;
            }
            else if(vec[j][1] >= intervals[i][0])
            {
                vec[j][1] = max(vec[j][1], intervals[i][1]);
                i++;
            } 
            else 
            {
                vec.push_back(intervals[i]);
                j++; i++;
            }
        }

        return vec;
    }
};