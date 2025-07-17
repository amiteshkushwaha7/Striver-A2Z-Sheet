class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

         sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
        

        int ans = 0;
        int i = 0, j = 1;

        while(j < n)
        {
            if(intervals[i][1] > intervals[j][0])
                ans++;
            else if(intervals[i][1] <= intervals[j][0])
                i = j;
            j++;
        }

        return ans;
    }
};