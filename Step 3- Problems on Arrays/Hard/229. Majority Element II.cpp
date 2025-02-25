//Optimal
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {   
        vector<int> ans;

        int n = nums.size();
        int elem1 = INT_MIN, elem2 = INT_MIN;
        int count1 = 0, count2 = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == elem1) 
                count1++;
            else if(nums[i] == elem2)  
                count2++;
            else if(count1 == 0)
            {
                elem1 = nums[i]; 
                count1 = 1;
            }
            else if(count2 == 0)
            {
                elem2 = nums[i]; 
                count2 = 1;
            }
            else
            {count1--; count2--;}
        }

        int elem1_Frequency = 0, elem2_Frequency = 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == elem1)
                elem1_Frequency++;
            if(nums[i] == elem2)
                elem2_Frequency++;
        }

         
        if(elem1_Frequency > n/3)
            ans.push_back(elem1);
        if(elem2_Frequency > n/3)
            ans.push_back(elem2);
         
        return ans;
    }
}; 


//Brute Force
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        vector<int> vec;
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int i = 0, j = 0;
        int count = 0;
        while(j<n)
        {
            while(j<n && nums[i] == nums[j])
            {
                count++; 
                j++;
            }
             
            if(count > n/3) vec.push_back(nums[i]);
            count = 0;
            i = j;
        }

        return vec; 
    }
};