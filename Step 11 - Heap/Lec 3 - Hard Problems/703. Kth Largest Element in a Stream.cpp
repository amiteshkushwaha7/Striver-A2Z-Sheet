class KthLargest {
private: 
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& arr) {
        this->k = k;
        for(int i=0; i<arr.size(); i++)
            pq.push(arr[i]);
        
        while(pq.size() > k)
            pq.pop();
    }
    
    int add(int val) {
        pq.push(val);

        while(pq.size() > k)
            pq.pop();
            
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */