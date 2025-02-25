//Optimal
class Solution {
public:
    int sumQuotient(vector<int> &arr, int divisor, int threshold)
    {
        int sum = 0;
        for(int i=0; i<arr.size(); i++)
        {
            sum += arr[i]/divisor;
            if(arr[i] % divisor > 0) sum++;
            
            if(sum > INT_MAX) return INT_MAX;
            if(sum > threshold) break;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int n = nums.size();
        int maxElm = INT_MIN;
        for(int i=0; i<n; i++)
            maxElm = max(maxElm, nums[i]);
        
        if(threshold == n) return maxElm;

        int left = 1, right = maxElm;
        int ans = 1;
        while(left <= right)
        {
            int mid = (left + right)/2;
            int sumQ = sumQuotient(nums, mid, threshold);

            if(sumQ <= threshold)
            {
                ans = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};

//Brute Force
class Solution {
public:
    int sumQuotient(vector<int> &arr, int divisor, int threshold)
    {
        int sum = 0;
        for(int i=0; i<arr.size(); i++)
        {
            sum += arr[i]/divisor;
            if(arr[i] % divisor > 0) sum++;
            if(sum > INT_MAX) return INT_MAX;
            if(sum > threshold) break;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int n = nums.size(), maxElm = INT_MIN;
        for(int i=0; i<n; i++) maxElm = max(maxElm, nums[i]);
        if(threshold == n) return maxElm;

        for (int divisor = 1; divisor <= maxElm; divisor++) 
        {
            int sumQ = sumQuotient(nums, divisor, threshold);
            if (sumQ <= threshold) return divisor;  
        }
        return -1;
    }
};