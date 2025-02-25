//Optimal


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void insertAtBottom(stack<int> &s, int min, int pos)
{
    if(s.size() == pos)
    {
        s.push(min);
        return;
    }
    
    int elm = s.top();
    s.pop();
    
    if(elm < min) swap(min, elm);
    insertAtBottom(s, min, pos);
    s.push(elm);
}

void SortedStack :: sort()
{
    int n = s.size();
    
    if(n == 0 || n == 1) return;
    
    int cnt = 0;
    while(cnt < n)
    {
        int min = s.top();
        s.pop();
        
        insertAtBottom(s, min, cnt);
        cnt++;
    }
}

//Better

// class SortedStack {
// public:
//     std::stack<int> s;
//     void sort();
// };

void SortedStack :: sort()
{
    std::map<int,int> mpp;
    while(!s.empty())   
    {
        mpp[s.top()]++;
        s.pop();
    }
    
    for(auto it: mpp)
    {
        int cnt = it.second;
        while(cnt > 0)
        {
            s.push(it.first);
            cnt--;
        }
    }
}

//optimal

// class SortedStack {
// public:
//     std::stack<int> s;
//     void sort();
// };

void SortedStack :: sort()
{
    std::vector<int> vec;
    while(!s.empty())   
    {
        vec.push_back(s.top());
        s.pop();
    }
    
    std::sort(vec.begin(), vec.end());   
    
    for(int i=0; i<vec.size(); i++) 
    {
        s.push(vec[i]);
    }
}