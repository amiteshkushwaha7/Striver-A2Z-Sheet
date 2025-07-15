
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize > 0) 
            return false;

        map<int, int> mpp;
        for(int i = 0; i < n; i++)
            mpp[hand[i]]++;

        auto i = mpp.begin();
        while(i != mpp.end()) 
        {
            int lastElm = i->first;
            auto j = next(i, 1);  

            mpp[lastElm]--;

            if (mpp[lastElm] == 0)
                mpp.erase(lastElm);
            else
                ++i; 

            int cnt = 1;
            while (cnt != groupSize && j != mpp.end() && lastElm + 1 == j->first)
            {
                cnt++;
                lastElm = j->first;

                mpp[j->first]--;

                if (mpp[j->first] == 0)
                    mpp.erase(j++);
                else
                    ++j;
            }

            if (cnt != groupSize)
                return false;

            i = mpp.begin();
        }

        return true;
    }
};
