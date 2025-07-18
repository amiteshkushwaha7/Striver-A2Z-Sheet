class Solution {
public:
    bool isColliding(vector<int> a, vector<int> b)
    {
        int a1 = a[0], a2 = a[1];
        int b1 = b[0], b2 = b[1];

        return max(a1, b1) <= min(a2, b2);
    }
    
    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& newinter) 
    {
        int n = inter.size();

        vector<vector<int>> ans;
        ans.push_back(newinter);

        for(int i=0; i<n; i++)
        {
            int val1 = ans.back()[0];
            int val2 = ans.back()[1]; 

            bool flag = isColliding(ans.back(), inter[i]);

            if(flag)
            {
                ans.pop_back();

                int start = min(val1, inter[i][0]);
                int end = max(val2, inter[i][1]);

                ans.push_back({start, end});
            }
            else if(val1 > inter[i][1])
            {
                ans.pop_back();
                ans.push_back(inter[i]);
                ans.push_back({val1, val2});
            }         
            else ans.push_back(inter[i]);
        }

        return ans;
    }
};  
