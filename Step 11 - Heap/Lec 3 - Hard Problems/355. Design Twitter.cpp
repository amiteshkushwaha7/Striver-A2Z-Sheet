class Twitter {
private:
    int timeStamp;
    unordered_map<int, vector<pair<int, int>>> tweets; 
    unordered_map<int, unordered_set<int>> followees; 

    void addTweetsToHeap(const vector<pair<int, int>>& userTweets, 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>& minHeap) 
        {
            for (const auto& tweet : userTweets) 
            {
                minHeap.push(tweet);
                if (minHeap.size() > 10)
                    minHeap.pop();
            }
    }

public:
    Twitter() {
        timeStamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(timeStamp++, tweetId);
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        addTweetsToHeap(tweets[userId], minHeap);

        for (int followeeId : followees[userId]) 
            addTweetsToHeap(tweets[followeeId], minHeap);

        vector<int> result;
        while (!minHeap.empty()) 
        {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        reverse(result.begin(), result.end()); 
        return result;
    }

    void follow(int followerId, int followeeId) 
    {
        if (followerId == followeeId) 
            return;
        followees[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};
