#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &boards, int mid, int k)
{
    int cntK = 1;  
    int cntTime = 0;   

    for (int i = 0; i < boards.size(); i++)
    {
        if (boards[i] > mid) return false;   
        if (cntTime + boards[i] <= mid) cntTime += boards[i];
        else {
          cntK++;
          cntTime = boards[i];
        }
    }

    return cntK <= k;   
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int n = boards.size();
    int low = *max_element(boards.begin(), boards.end());   
    int high = accumulate(boards.begin(), boards.end(), 0);   
    int ans = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;  
        if (isPossible(boards, mid, k))
        {
            ans = mid;  
            high = mid - 1;  
        }
        else low = mid + 1;  
    }

    return ans;
}
