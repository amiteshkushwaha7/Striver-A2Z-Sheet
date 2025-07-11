class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mpp;

        int subArrays = 0;
        int i = 0, j = 0;

        while (j < n) {
            // Always update or insert the latest index for nums[j]
            mpp[nums[j]] = j;

            // If new element causes size > k, fix window
            if (mpp.size() > k) {
                // Find minimum index in mpp to determine where to move 'i'
                int minIndex = INT_MAX, minKey = -1;
                for (auto& p : mpp) {
                    if (p.second < minIndex) {
                        minIndex = p.second;
                        minKey = p.first;
                    }
                }
                i = minIndex + 1;
                mpp.erase(minKey);
            }

            // If window has exactly k distinct integers
            if (mpp.size() == k) {
                // Count number of duplicates of leftmost element to compute left options
                int minIndex = INT_MAX, minKey = -1;
                int maxIndex = INT_MIN;
                for (auto& p : mpp) {
                    if (p.second < minIndex) {
                        minIndex = p.second;
                        minKey = p.first;
                    }
                    if (p.second > maxIndex) {
                        maxIndex = p.second;
                    }
                }

                int left = minIndex - i;
                int right = j - maxIndex - 1;

                subArrays += (left * right) + left + right + 1;
            }

            j++;
        }

        return subArrays;
    }
};
