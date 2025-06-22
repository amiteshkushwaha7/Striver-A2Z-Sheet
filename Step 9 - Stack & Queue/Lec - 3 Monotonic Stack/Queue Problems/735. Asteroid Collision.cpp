//Optimal
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        
        int i=0;
        while(i<n)
        {
            if(st.empty() || asteroids[i] > 0 || st.top() < 0)
                st.push(asteroids[i++]);
            else
            {
                if(st.top() > 0 && abs(asteroids[i]) > st.top()) st.pop();
                else if(st.top() > 0 && abs(asteroids[i]) == st.top()) {st.pop(); i++;}
                else i++;
            }
        }

        vector<int> ans(st.size());

        for(int j=ans.size()-1; j>=0; j--)
        {
            ans[j] = st.top();
            st.pop();
        }

        return ans;
    }
};