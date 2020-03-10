#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
    	//https://leetcode-cn.com/problems/daily-temperatures/solution/leetcode-tu-jie-739mei-ri-wen-du-by-misterbooo/
    	//利用栈
    	stack<int> cur;
    	vector<int> res(T.size());
    	if(T.size()>=0)
    	{
    		int temp[T.size()];
	    	for(int i=0;i<T.size();i++)
	    	{
	    		if(cur.empty())
	    		{
	    			cur.push(i);
	    		}else
	    		{
	    			while(!cur.empty() && T[i] > T[cur.top()])
	    			{
	    				int dis = i - cur.top();
	    				res[cur.top()] = dis;
	    				cur.pop();
	    			}
	    			cur.push(i);
	    		}
	    	}
	    	while(!cur.empty())
	    	{
	    		res.push_back(0);
	    		cur.pop();
	    	}
	    	res.push_back(0);
	    	//res[T.size()-1] = 0;
    	}

    	//vector<int> res;
    	return res;
        
    }
};

int main()
{
	Solution * mySolution = new Solution();
	int input[8] = {73, 74, 75, 71, 69, 72, 76, 73};
	vector<int> vinput(input,input+8);
	vector<int> res = mySolution->dailyTemperatures(vinput);
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<endl;
	}
	delete mySolution;
	return 0;
}