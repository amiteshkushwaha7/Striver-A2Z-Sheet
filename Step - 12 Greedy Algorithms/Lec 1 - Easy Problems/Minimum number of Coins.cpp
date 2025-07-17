// User function Template for C++

class Solution {
  public:
    vector<int> minPartition(int amount) {
        vector<int> ans;
        
        while(amount > 0)
        {
            if(amount >= 2000)
            {
                int cnt = amount / 2000;
                while(cnt)
                {
                    ans.push_back(2000);
                    cnt--;
                }
                amount = amount % 2000;
            }
            else if(amount >= 500 && amount < 2000)
            {
                int cnt = amount / 500;
                while(cnt)
                {
                    ans.push_back(500);
                    cnt--;
                }
                amount = amount % 500;
            }
            else if(amount >= 200 && amount < 500)
            {
                int cnt = amount / 200;
                while(cnt)
                {
                    ans.push_back(200);
                    cnt--;
                }
                amount = amount % 200;
            }
            else if(amount >= 100 && amount < 200)
            {
                int cnt = amount / 100;
                while(cnt)
                {
                    ans.push_back(100);
                    cnt--;
                }
                amount = amount % 100;
            }
            else if(amount >= 50 && amount < 100)
            {
                int cnt = amount / 50;
                while(cnt)
                {
                    ans.push_back(50);
                    cnt--;
                }
                amount = amount % 50;
            }
            else if(amount >= 20 && amount < 50)
            {
                int cnt = amount / 20;
                while(cnt)
                {
                    ans.push_back(20);
                    cnt--;
                }
                amount = amount % 20;
            }
            else if(amount >= 10 && amount < 20)
            {
                int cnt = amount / 10;
                while(cnt)
                {
                    ans.push_back(10);
                    cnt--;
                }
                amount = amount % 10;
            }
            else if(amount >= 5 && amount < 10)
            {
                amount = amount % 5;
                ans.push_back(5);
            }
            else if(amount >= 2 && amount < 5)
            {
                int cnt = amount / 2;
                while(cnt)
                {
                    ans.push_back(2);
                    cnt--;
                }
                amount = amount % 2;
            }
            else
            {
                amount = amount - 1;
                ans.push_back(1);
            }
        }
        
        return ans;
    }
};