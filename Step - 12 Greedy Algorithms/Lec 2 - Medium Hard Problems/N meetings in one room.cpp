class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(int i = 0; i < n; i++)
            pq.push({end[i], start[i]}); 

        int cnt = 0;
        int last_end = -1; 
        
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            if (p.second > last_end) 
            { 
                cnt++;
                last_end = p.first;
            }
        }
        
        return cnt;
    }
};
