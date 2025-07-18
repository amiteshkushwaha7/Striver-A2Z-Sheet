class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        
        // Max-heap ordered by deadline descending
        priority_queue<pair<int,int>> jobs;
        for(int i=0; i<n; i++)
            jobs.push({ deadline[i], profit[i] });
        
        int job = 0;
        int prof = 0;
        
        priority_queue<int> pq; 

        int curr = jobs.top().first;
        
        while(curr > 0) 
        {
            while(!jobs.empty() && jobs.top().first == curr) 
            {
                pq.push(jobs.top().second);
                jobs.pop();
            }

            if(!pq.empty()) 
            {
                prof += pq.top();
                pq.pop();
                job++;
            }

            curr--; 
        }

        return { job, prof };
    }
};
