class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int len = 0;

        int i = 0, j = 0;
        while(j<n && fruits[j] == fruits[0])
        {
            len++;
            j++;
        }

        if(j >= n) return len;

        pair<int,int> type1;
        pair<int,int> type2;

        type1 = {fruits[0], j};
        type2 = {fruits[j], 1};
        j++;

        while(j<n)
        {
            if(fruits[j] == type1.first)
                type1.second++;
            else if(fruits[j] == type2.first)
                type2.second++;
            else
            {
                len = max(len, j-i);
                pair<int,int> newType = {fruits[j], 1};

                while(type1.second > 0 && type2.second > 0)
                {
                    if(fruits[i] == type1.first)
                        type1.second--;
                    else type2.second--;
                    i++;
                }

                if(type1.second <= 0)
                    type1 = newType;
                else type2 = newType;
            }

            j++;
        }

        len = max(len, j-i);

        return len;
    }
};