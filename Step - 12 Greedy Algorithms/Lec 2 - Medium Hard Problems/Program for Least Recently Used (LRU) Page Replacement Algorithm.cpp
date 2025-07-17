class Solution {
  public:
    int pageFaults(int n, int capacity, int pages[]) {
        unordered_map<int,int> uMpp;
        map<int,int> mpp;

        int id = 1, i = 0;
        int pf = 0; 

        while(mpp.size() < capacity && i < n)
        {
            if(uMpp.find(pages[i]) == uMpp.end())
            {
                uMpp[pages[i]] = id;
                mpp[id] = pages[i];
                
            }
            else
            {
                int old_id = uMpp[pages[i]];
                mpp.erase(old_id);
                uMpp[pages[i]] = id;
                mpp[id] = pages[i];
                
            }

            i++; 
            id++;
        }

        for(int j=i; j<n; j++)
        {
            if(uMpp.find(pages[j]) == uMpp.end())
            {
                auto it = mpp.begin();

                mpp.erase(it->first);
                uMpp.erase(it->second);

                uMpp[pages[j]] = id;
                mpp[id] = pages[j];

                pf++;
            }
            else
            {
                int old_id = uMpp[pages[j]];

                mpp.erase(old_id);

                uMpp[pages[j]] = id;
                mpp[id] = pages[j];
                
            }

            id++;
        }

        return pf;
    }
};
