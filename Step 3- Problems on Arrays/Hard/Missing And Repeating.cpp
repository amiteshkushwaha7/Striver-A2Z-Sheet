class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) 
    {
        int n = arr.size();
        
        long long actual_sum = 0, expected_sum = 0;
        long long actual_square_sum = 0, expected_square_sum = 0;
    
        for(int i=0; i<n; i++)
        {
            actual_sum = actual_sum + arr[i];
            expected_sum = expected_sum + (i+1);
            
            actual_square_sum = actual_square_sum + (arr[i]*arr[i]);
            expected_square_sum = expected_square_sum + ((i+1)*(i+1));
        }
        
        long long sum_diff = actual_sum - expected_sum;
        long long square_diff = (actual_square_sum - expected_square_sum)/sum_diff;
        
        int repeating_num = (sum_diff + square_diff)/2;
        int missing_num = square_diff - repeating_num;
        
        return {repeating_num, missing_num};
        
    }
};