//Optimal
class Solution {
public:
    int trap(vector<int>& arr) 
    {
        int n = arr.size();
        
        int i = 0;
        while(i<n && arr[i] == 0) i++;

        bool flag = false;
        int water = 0;
        while(i<n)
        {
            int j = i+1;
            int tempWater = 0;
            while(j<n && arr[j] < arr[i])
            {
                tempWater += arr[i] - arr[j];
                j++;
            } 

            if(i < n && j == n)
            {flag = true; break;}

            water += tempWater;
            i = j;
        }

        if(flag)
        {
            int j = n-1;
            while(j>i)
            {
                int k = j-1;
                int tempWater = 0;
                while(k>i && arr[j] > arr[k])
                {
                    tempWater += arr[j] - arr[k];
                    k--;
                }
                water += tempWater;
                j = k;
            }
        }

        return water;
    }
};