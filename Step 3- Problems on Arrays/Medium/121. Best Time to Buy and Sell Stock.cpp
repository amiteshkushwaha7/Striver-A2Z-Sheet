//Optimal
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int profit= 0;
        int i = 0, j = 0;
        while(j<n)
        {
            if(prices[j] - prices[i] >= 0)
            {
                profit = max(profit, prices[j]-prices[i]);
                j++;
            }
            else i = j;
        } 

        return profit;
    }
};



//Brute Force
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int profit= 0;
        for(int i=0; i<n; i++)
        {
            int buy = prices[i];
            int sell = prices[i];
            for(int j=i+1; j<n; j++)
                if(sell < prices[j]) sell = prices[j];

            profit = max(profit, sell-buy);
        } 

        return profit;
    }
};