//Optimal
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;

        for(int i = 0; i < k; i++) {
            while(!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
 
        for(int i = k; i < n; i++) { 
            ans.push_back(nums[dq.front()]);
 
            while(!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
 
            while(!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();

            dq.push_back(i);
        }
 
        ans.push_back(nums[dq.front()]);

        return ans;
    }
};

//Better
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int n = nums.size();

        vector<int> ans;
        priority_queue<pair<int,int>> pq;

        for(int i=0; i<k-1; i++)
            pq.push({nums[i], i});

        int i = 0;
        int j = k-1;
        while(j < n)
        {
            pq.push({nums[j], j});

            while(!pq.empty() && pq.top().second < i)
                pq.pop();

            auto p = pq.top();

            if(p.second >= i && p.second <= j)
                ans.push_back(p.first);

            i++; j++;
        }

        return ans;
    }
};

//Brute
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int n = nums.size();

        vector<int> ans;
        map<int,int> mpp;

        for(int i=0; i<k-1; i++)
        {
            if(mpp.find(nums[i]) == mpp.end())
                mpp[nums[i]] = 1;
            else mpp[nums[i]]++;
        }
        
        int i = 0; 
        int j = k-1;
        while(j<n)
        {
            if(mpp.find(nums[j]) == mpp.end())
                mpp[nums[j]] = 1;
            else mpp[nums[j]]++;  
            
            ans.push_back((--mpp.end())->first);

            if(mpp[nums[i]] == 1)
                mpp.erase(nums[i]);
            else mpp[nums[i]]--;    

            i++; j++;
        }

        return ans;
    }
};