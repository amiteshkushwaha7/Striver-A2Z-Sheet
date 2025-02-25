// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) 
    {
        int left = 1, right = n;
        while(left <= right)
        {
            int mid = (left + right)/2;
            
            int square = mid * mid;
            if(square == n) return mid;
            else if(square > n) right = mid - 1;
            else left = mid;
            
            if(left == right) return left;
            else if(right - left == 1)
            {
                if(right*right <= n) return right;
                else return left;
            }
        }
        
        return 1;
    }
};