class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int i = 0, j = 0;
        int range = n-k, sum = 0;

        while(j < range)
            sum += cardPoints[j++];

        int indx = j-1;
        int tempSum = sum, points = 0;

        while(j < n)
        {
            tempSum = tempSum + cardPoints[j] - cardPoints[i++];

            if(tempSum <= sum)
            {
                sum = tempSum;
                indx = j;
            }

            j++;
        }
 
        for(int k=0; k<n; k++)
        {
            if(k >= indx+1-range && k<=indx)
                continue;
            points += cardPoints[k];
        }

        return points;
    }
};