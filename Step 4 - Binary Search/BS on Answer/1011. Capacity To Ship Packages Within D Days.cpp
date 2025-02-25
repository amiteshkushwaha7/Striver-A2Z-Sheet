//Optimal
class Solution {
public:
    int countDays(vector<int> &arr, int capacity)
    {
        int cntDays = 1, tempCapacity = 0; 
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] > capacity) 
                return INT_MAX; 

            tempCapacity += arr[i];
            if(tempCapacity > capacity)
            {
                cntDays++;   
                tempCapacity = arr[i];  
            }
        }
        return cntDays;
    }


    int shipWithinDays(vector<int>& weights, int days) 
    {
        int weightsSum = 0;
        for(int i=0; i<weights.size(); i++)
        {
            weightsSum += weights[i];
        }

        if(days == 1) return weightsSum;
        else if(days == weightsSum) return 1;

        int left = 1, right = weightsSum;
        int ans = 1;
        while(left <= right)
        {
            int mid = (left + right)/2;
            int tempDays = countDays(weights, mid);
            
            if(tempDays <= days)
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
    int countDays(vector<int> &arr, int capacity)
    {
        int cntDays = 1, tempCapacity = 0; 
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] > capacity) return INT_MAX; 
            tempCapacity += arr[i];
            if(tempCapacity > capacity)
            {cntDays++; tempCapacity = arr[i];  }
        }
        return cntDays;
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int weightsSum = 0;
        for(int i=0; i<weights.size(); i++) weightsSum += weights[i];
        if(days == 1) return weightsSum;
        else if(days == weightsSum) return 1;

        for (int i = 1; i <= weightsSum; i++) 
        {
            int tempDays = countDays(weights, i);
            if (tempDays <= days) return i; 
        } 
        return -1;
    }
};