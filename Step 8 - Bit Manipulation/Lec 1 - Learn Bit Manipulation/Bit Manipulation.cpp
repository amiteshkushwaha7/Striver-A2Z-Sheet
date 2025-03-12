class Solution {
    
    public:
      void bitManipulation(int num, int i) 
      {
          int get, set = num, clear = num;
  
          if ((num & (1 << (i-1))) == 0) 
          {  
              get = 0;
              set = num | (1 << (i-1)); 
              
          } 
          else get = 1;
          
          clear = num & ~(1 << (i-1));
  
          cout << get << " " << set << " " << clear;  
      }
  };