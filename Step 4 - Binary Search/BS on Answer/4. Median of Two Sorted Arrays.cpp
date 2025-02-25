//Brute Force
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> vec;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1+n2;

        int i=0, j=0;
        while(i<n1 && j<n2)
        {
            if(nums1[i] <= nums2[j]) vec.push_back(nums1[i++]);
            else vec.push_back(nums2[j++]);
        }

        while(i<n1) vec.push_back(nums1[i++]);
        while(j<n2) vec.push_back(nums2[j++]);

        if(n%2 > 0) return vec[n/2];
        return (vec[n/2] + vec[n/2 - 1])/2.0;
    }
};





//Optimal
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int x = nums1.size();
        int y = nums2.size();

        int low = 0, high = x;
        while (low <= high) 
        {
            int partitionX = (low + high) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;
 
            int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minX = (partitionX == x) ? INT_MAX : nums1[partitionX];

            int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minY = (partitionY == y) ? INT_MAX : nums2[partitionY];
 
            if (maxX <= minY && maxY <= minX) 
            {
                if ((x + y) % 2 == 0) return (max(maxX, maxY) + min(minX, minY)) / 2.0;
                else return max(maxX, maxY);
            } 
            else if (maxX > minY) high = partitionX - 1;
            else low = partitionX + 1;
        }

        return -1;
    }
};