class Solution {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> train;
        
        for(int i=0; i<n; i++)
            train.push({arr[i], dep[i]});
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        pq.push(train.top().second);
        train.pop();
        int ans = 1;
        
        while(!train.empty())
        {
            while (!pq.empty() && pq.top() < train.top().first) 
                pq.pop();

            pq.push(train.top().second);
            
            int size = pq.size();
            ans = max(ans, size);
            
            train.pop();
        }
        
        return ans;
    }
};
