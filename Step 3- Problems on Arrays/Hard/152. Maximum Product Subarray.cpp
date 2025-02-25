#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int n = nums.size();
        long long maxProduct = nums[0], minProduct = nums[0], result = nums[0]; 
        long long temp_max, temp_min;

        for (int i=1; i<n; i++)   
        {
            long long num = nums[i];
            temp_max = max(num, max(maxProduct * num, minProduct * num));
            temp_min = min(num, min(maxProduct * num, minProduct * num));

            maxProduct = temp_max;
            minProduct = temp_min;

            result = max(result, maxProduct);
        }

        return result;   
    }
};