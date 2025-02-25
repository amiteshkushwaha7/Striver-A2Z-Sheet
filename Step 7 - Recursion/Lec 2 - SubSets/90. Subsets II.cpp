//Optimal
class Solution {
public:
    void generateSubSets(vector<int> &arr, int indx, vector<int> vec, vector<vector<int>> &ans)
    {
        if(indx >= arr.size())
        {
            ans.push_back(vec);
            return;
        }

        vec.push_back(arr[indx]);
        generateSubSets(arr, indx+1, vec, ans);

        vec.pop_back();
        int i = indx+1;
        while(i < arr.size() && arr[i] == arr[i-1]) i++;
        generateSubSets(arr, i, vec, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> empty;

        generateSubSets(nums, 0, empty, ans);
        
        return ans;
    }
};


//Brute Force
class Solution {
public:
    void generateSubSets(vector<int> &arr, int indx, vector<int> vec, set<vector<int>> &ans)
    {
        if(indx >= arr.size())
        {
            sort(vec.begin(), vec.end());
            ans.insert(vec);
            return;
        }

        generateSubSets(arr, indx+1, vec, ans);

        vec.push_back(arr[indx]);
        generateSubSets(arr, indx+1, vec, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        set<vector<int>> subSets;
        vector<int> empty;
        generateSubSets(nums, 0, empty, subSets);

        vector<vector<int>> ans;
        ans.assign(subSets.begin(), subSets.end());
        return ans;
    }
};