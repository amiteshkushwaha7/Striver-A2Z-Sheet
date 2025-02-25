//Brute Force
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) 
    {
        vector<int> vec;
        
        int size1 = arr1.size();
        int size2 = arr2.size();
        
        int i = 0, j = 0;
        while(i < size1 && j < size2)
        {
            if(arr1[i] <= arr2[j])
            {
                vec.push_back(arr1[i]);
                i++;
            }
            else
            {
                vec.push_back(arr2[j]);
                j++;
            }
        }
        
        while(i < size1) vec.push_back(arr1[i++]);
        while(j <size2) vec.push_back(arr2[j++]);
        
        return vec[k-1];
    }
};



//Better 
int kthElement(int k, vector<int>& arr1, vector<int>& arr2) 
    {
        int size1 = arr1.size();
        int size2 = arr2.size();
        
        int i = 0, j = 0;
        int cnt = 0;
        while(i < size1 && j < size2)
        {
            cnt++;
            if(arr1[i] <= arr2[j])
            {
                if(cnt == k) return arr1[i];
                i++;
            }
            else
            {
                if(cnt == k) return arr2[j];
                j++;
            }
        }
        
        while(i < size1)
        {
            cnt++;
            if(cnt == k) return arr1[i];
            i++;
        }
        
        while(j <size2)
        {
            cnt++;
            if(cnt == k)return arr1[i];
            j++;
        }
        
        return -1;
    }



//Optimal 
int kthElement(int k, vector<int>& arr1, vector<int>& arr2) 
    {
        if (arr1.size() > arr2.size()) return kthElement(k, arr2, arr1);
    
        int n1 = arr1.size();
        int n2 = arr2.size();
    
        int low = max(0, k - n2), high = min(k, n1);
        while (low <= high) 
        {
            int partition1 = (low + high) / 2;
            int partition2 = k - partition1;
    
            int maxLeft1 = (partition1 == 0) ? INT_MIN : arr1[partition1 - 1];
            int minRight1 = (partition1 == n1) ? INT_MAX : arr1[partition1];
    
            int maxLeft2 = (partition2 == 0) ? INT_MIN : arr2[partition2 - 1];
            int minRight2 = (partition2 == n2) ? INT_MAX : arr2[partition2];
    
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) return max(maxLeft1, maxLeft2);
            else if (maxLeft1 > minRight2) high = partition1 - 1;
            else low = partition1 + 1;
        }
        return -1;
    }