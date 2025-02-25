//Optimal
class Solution {
public:
    int romanToInt(string s) 
    {
        int n = s.size();
        map<char,int> mpp = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
            {'C', 100},{'D', 500}, {'M', 1000}
        };

        int ans = 0, i = 0;
        while(i<s.size())
        {
            if(i+1 < n && mpp[s[i+1]] > mpp[s[i]])
            {
                ans = ans + (mpp[s[i+1]] - mpp[s[i]]);
                i += 2;
            }
            else 
            {
                ans += mpp[s[i]];
                i++;
            }
        } 
        return ans;   
    }
};

//Optimal 2
class Solution {
public:
    int romanToInt(string s) 
    {
        int ans = 0;
        int i = 0;
        while(i<s.size())
        {
            if(s[i] == 'M') {ans += 1000; i++;}
            else if(s[i] == 'D')
            {
                if(s[i+1] == 'M') {ans += 500; i += 2;}
                else {ans += 500; i++;}
            }
            else if(s[i] == 'C') 
            {
                if(s[i+1] == 'D') {ans += 400; i += 2;}
                else if(s[i+1] == 'M') {ans += 900; i += 2;}
                else {ans += 100; i++;}
            }
            else if(s[i] == 'L')
            {
                if(s[i+1] == 'C') {ans += 50; i += 2;}
                else if(s[i+1] == 'D') {ans += 450; i += 2;}
                else if(s[i+1] == 'M') {ans += 950; i += 2;}
                else {ans += 50; i++;}
            }
            else if(s[i] == 'X') 
            {
                if(s[i+1] == 'L') {ans += 40; i += 2;}
                else if(s[i+1] == 'C') {ans += 90; i += 2;}
                else if(s[i+1] == 'D') {ans += 490; i += 2;}
                else if(s[i+1] == 'M') {ans += 990; i += 2;}
                else {ans += 10; i++;}
            } 
            else if(s[i] == 'V') 
            {
                if(s[i+1] == 'X') {ans += 5; i += 2;}
                else if(s[i+1] == 'L') {ans += 45; i += 2;}
                else if(s[i+1] == 'C') {ans += 95; i += 2;}
                else if(s[i+1] == 'D') {ans += 495; i += 2;}
                else if(s[i+1] == 'M') {ans += 995; i += 2;}
                else {ans += 5; i++;}
            }
            else
            {
                if(s[i+1] == 'V') {ans += 4; i += 2;}
                else if(s[i+1] == 'X') {ans += 9; i += 2;}
                else if(s[i+1] == 'L') {ans += 49; i += 2;}
                else if(s[i+1] == 'C') {ans += 99; i += 2;}
                else if(s[i+1] == 'D') {ans += 499; i += 2;}
                else if(s[i+1] == 'M') {ans += 999; i += 2;}
                else {ans += 1; i++;}
            }
        } 
        return ans;   
    }
};