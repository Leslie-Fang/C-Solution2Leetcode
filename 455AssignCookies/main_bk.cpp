#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
    	sort (g.begin(), g.end()); 
    	sort (s.begin(), s.end());   
        return subcontent(g,s,0,-1,-1);
    }
    int subcontent(vector<int> g, vector<int> s,int content,int pos1,int pos2)
    {

    	vector<int> res;
    	if(pos1 != -1)
    	{
    		g.erase(g.begin()+pos1);
    	}
    	if(pos2 != -1)
    	{
    		s.erase(s.begin()+pos2);
    	}
    	if(g.size() == 0 || s.size() == 0)
    	{
    		return content;
    	}
    	int count = 0;
    	for(vector<int>::iterator it=s.begin();it != s.end();it++)
    	{
    		if(*it >= g[0])
    		{
    			res.push_back(subcontent(g,s,content+1,0,count));
    		}
    		count += 1;
    	}
    	if(res.size() == 0)
    	{
    		return content;
    	}
    	int max = res[0];
    	for(vector<int>::iterator it=res.begin();it != res.end();it++)
    	{
    		max = *it > max ? *it : max;
    	}
    	return max;
    }
};

int main()
{
	int a1[4] = {9,10,8,7};
	int b1[2] = {7,8};
	vector<int> a(a1,a1+4);
	vector<int> b(b1,b1+2);
	Solution * mySolution = new Solution();

	cout<<mySolution->findContentChildren(a,b)<<endl;


}