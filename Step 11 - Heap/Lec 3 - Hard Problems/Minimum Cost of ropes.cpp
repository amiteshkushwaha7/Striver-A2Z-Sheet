class Solution {
public:
    int minCost(vector<int>& arr) {
        int n = arr.size();
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; i++)
            pq.push(arr[i]);
        
        int cost = 0;
        while(pq.size() > 1)
        {
            int sum = pq.top(); pq.pop();
            sum += pq.top(); pq.pop();
            
            pq.push(sum);
            cost += sum;
        }
        
        return cost;
    }
};
    