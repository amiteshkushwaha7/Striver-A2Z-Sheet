class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        if(s.size() != goal.size()) return false;

        string text = s + s;
        int gLen = goal.size(), tLen = text.size();

        int i = 0, j = 0, indx = -1;
        while(i < tLen && j < gLen)
        {
            if(text[i] == goal[j])
            {
                while(j < gLen && text[i] == goal[j])
                {
                    i++;j++;
                    if(indx == -1 && text[i] == goal[0]) indx = i;
                }

                if(j == gLen) return true;
                if(indx != -1)
                {i = indx; indx = -1;}
                else j = 0;
            }
            else i++;
        }
        return false;
    }
};