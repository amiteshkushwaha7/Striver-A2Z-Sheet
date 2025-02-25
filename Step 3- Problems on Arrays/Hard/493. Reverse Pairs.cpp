//Optimal
class Solution {
public:
    int merge(vector<int> &arr, int start, int mid, int end)
    {
        vector<int> vec;

        int i = start;
        int j = mid+1;
        int count = 0;

        for (int i = start; i <= mid; i++) {
            while (j <= end && arr[i] > 2LL * arr[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
        
        i = start;
        j = mid+1;
        while(i <= mid && j<=end)
        {
            if(arr[i] <= arr[j])
                vec.push_back(arr[i++]);
            else
                vec.push_back(arr[j++]);
        }

        while(i <= mid) vec.push_back(arr[i++]);
        while(j <= end) vec.push_back(arr[j++]);

        int k = 0;
        for(int i=start; i<=end; i++) arr[i] = vec[k++];

        return count;
    }

    int merge_sort(vector<int> &arr, int start, int end)
    {
        if(start >= end) return 0;

        int mid = (start+end)/2;
        int reverse = 0;

        reverse += merge_sort(arr, start, mid);
        reverse += merge_sort(arr, mid+1, end);
        reverse += merge(arr, start, mid, end);
        return reverse;
    }

    int reversePairs(vector<int>& nums) 
    {
        return merge_sort(nums, 0, nums.size()-1);
    }
};


//Brute Force
class Solution {
public:
    int reversePairs(vector<int>& nums) 
    {
        int n = nums.size();
        int count = 0;
        for(int i=n-1; i>0; i--)
        {
            long long x = (long long)nums[i];
            for(int j=i-1; j>=0; j--)
            {
                long long y = (long long)nums[j];
                if(y > 2*x) count++;
            }
        }  

        return count;  
    }
};