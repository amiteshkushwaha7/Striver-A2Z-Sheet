class Solution {
    public:
      int setBit(int n) 
      {
          int i = 0;
          while(true)
          {
              if((n & (1 << i)) == 0)
                  return n | (1 << i);
              i++;
          }
      }
      
  };