class Solution {
public:
    bool isPalindrome(int x) {
        long long temp = x;
        long long revNum=0;

        while(temp>0)
        {
            if(revNum*10 > INT_MAX) return false;
            
            revNum = (revNum*10) + (temp%10);
            temp = temp/10;
        }

        if(revNum == x) return true;
        return false;
    }
};