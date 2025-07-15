class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        vector<int> ans;
        priority_queue<pair<int, pair<int,int>>> pq;
        set<pair<int, int>> visited;
        
        int i = 0;
        int j = 0;
        pq.push({a[i] + b[j], {0, 0}});
        visited.insert({0, 0});
        
        while (ans.size() < k && !pq.empty()) 
        {
            int val = pq.top().first;
            auto p = pq.top().second;
            pq.pop();
            
            ans.push_back(val);
            
            if (p.first + 1 < n && visited.find({p.first + 1, p.second}) == visited.end()) 
            {
                pq.push({a[p.first + 1] + b[p.second], {p.first + 1, p.second}});
                visited.insert({p.first + 1, p.second});
            }
            
            if (p.second + 1 < n && visited.find({p.first, p.second + 1}) == visited.end()) 
            {
                pq.push({a[p.first] + b[p.second + 1], {p.first, p.second + 1}});
                visited.insert({p.first, p.second + 1});
            }
        }
        
        return ans;
    }
};
