// Approach 1
class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        unordered_map<char, int> mpp;
        for (char task : tasks)
            mpp[task]++;

        priority_queue<pair<int, char>> pq;
        for (auto it : mpp)
            pq.push({it.second, it.first});

        queue<pair<int, char>> cooldown;
        int time = 0;

        while (!pq.empty() || !cooldown.empty()) 
        {
            time++;

            if (!cooldown.empty() && cooldown.front().first == time) 
            {
                pq.push({mpp[cooldown.front().second], cooldown.front().second});
                cooldown.pop();
            }

            if (!pq.empty()) 
            {
                auto [freq, ch] = pq.top();
                pq.pop();

                mpp[ch] = freq - 1;
                if (mpp[ch] > 0) {
                    cooldown.push({time + k + 1, ch});
                }
            }
        }

        return time;
    }
};


// Approach 2
class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        int n = tasks.size();
        map<char,int> mpp;

        for(int i = 0; i < n; i++)
            mpp[tasks[i]]++;

        int maxFeq = 0;
        for(auto& it : mpp)
            maxFeq = max(maxFeq, it.second); 

        int cntMaxFeqElm = 0;
        for(auto& it : mpp)
            if(it.second == maxFeq)
                cntMaxFeqElm++;

        int partCount = maxFeq - 1;
        int partLength = k + 1;
        int emptySlots = partCount * partLength + cntMaxFeqElm;

        return max(n, emptySlots);
    }
};