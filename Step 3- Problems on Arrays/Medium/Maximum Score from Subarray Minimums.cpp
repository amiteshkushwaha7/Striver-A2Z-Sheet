//Optimal
class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) 
    {
        int n = arr.size();
        int sum = 0, maxSum = 0;
        int i=0, j=1;
        while(j<n)
        {
            sum = arr[i] + arr[j];
            maxSum = max(sum, maxSum);
            sum = 0;
            i++; j++;
        }
        
        return maxSum;
    }
};

//Brute Force
class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) 
    {
        int n = arr.size();
        int maxSum = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                if(j-i+1 >= 2)
                {
                    int firstMin = arr[i], secondMin = INT_MAX;
                    for(int k=i+1; k<=j; k++)
                    {
                        if(firstMin > arr[k])
                        {
                            secondMin = firstMin;
                            firstMin = arr[k];
                        }
                    
                        if(secondMin > arr[k] && arr[k] != firstMin)
                            secondMin = arr[k];
                    }
                
                    if(secondMin == INT_MAX) secondMin = firstMin;
                
                    int minSum = firstMin + secondMin;
                    maxSum = max(maxSum, minSum);
                }
            }
        }
        
        return maxSum;
    }
};