#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <time.h>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int m, int n, int index=30) {
    	int res=0;
    	if(n-m <= 200)
    	{
    		res = m;
    		if(m == 2147483647)
    		{
    			return 2147483647;
    		}
    		for(long i=m+1;i<=n;i++)
    		{
    			res = res & i;
    		}
    		return res;
    	}
    	int start = 0, end=0;
    	if(m<2 && n<2)
    	{
    		return m&n;
    	}
    	int find_end = 0;
    	while(index >= 0)
    	{
    		if(n-pow(2,index) >= 0 && !find_end)
    		{
    			end = index;
    			find_end = 1;
    		}
    		if(m-pow(2,index) >= 0)
    		{
    			start = index+1;
    			break;
    		}
    		index -= 1;
    	}
    	if(start > end)
    	{
    		int add = pow(2,end);
    		res = res + rangeBitwiseAnd(m-add,n-add,end-1) + add;
    		return res;
    	}else
    	{
    		return 0;
    	}
        return res;
    }

    int rangeBitwiseAnd2(int m, int n)
    {
    	int res = m;
    	for(int i=m+1;i<=n;i++)
    	{
    		res = res & i;
    	}
    	return res;
    }
};
int main()
{
	string input1,input2;
	int m,n;
	getline(cin,input1);
	getline(cin,input2);
	istringstream iss(input1);
	iss >> m;
	iss.clear();
	istringstream iss2(input2);
	iss2 >> n;
	iss2.clear();
	cout<<m<<endl;
	cout<<n<<endl;
	Solution * mySolution = new Solution();
	clock_t startTime,endTime;
	startTime = clock();
	cout<<mySolution->rangeBitwiseAnd(m,n)<<endl;
	endTime = clock();
	cout << "Totle Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	delete mySolution;
	return 0;
}