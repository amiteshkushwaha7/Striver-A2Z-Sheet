class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        map<int,int> mpp;
        for(int i=0; i<n; i++)
            mpp[nums[i]]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(auto it=mpp.begin(); it!=mpp.end(); it++)
            pq.push({it->second, it->first});

        while (pq.size() > k) 
            pq.pop();
        
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
