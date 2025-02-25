class Solution {
public:
    int reverse(int x) {
        long long temp = x;
        long long revNum=0;
        int sign = 1;
        
        if(temp<0)
        {
            sign = -1;
            temp = -1*temp;
        }

        while(temp>0)
        {
            if(revNum*10 > INT_MAX) return 0;
            if(revNum*10 < INT_MIN) return 0;

            revNum = (revNum*10) + (temp%10);
            temp=temp/10;
        }   

        return sign*revNum;
    }
};