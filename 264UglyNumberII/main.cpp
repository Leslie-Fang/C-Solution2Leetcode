#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
    	int count = 1;
    	int res = 1;
    	int i=0,j=0,k=0;
    	vector<int> v;
    	while(count < n)
    	{
    		res = minest(v[i]*2,v[j]*3,v[k]*5);
    		v.push_back(res);
    		if(res == v[i]*2) i=i+1;
    		if(res == v[j]*3) j=j+1;
    		if(res == v[k]*5) k=k+1;
    		count += 1;
    	}
    	return res;
    }
    int minest(int a,int b,int c)
    {
    	int minest = a;
    	if(minest > b)
    	{
    		minest = b;
    	}
    	if(minest > c)
    	{
    		minest = c;
    	}
    	return minest;
    }
};

int main()
{
	Solution * mySolution = new Solution();
	cout<<mySolution->nthUglyNumber(10)<<endl;
	return 0;
}