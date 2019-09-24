#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
    	cout<<"m is:"<<m<<endl;
    	cout<<"n is:"<<n<<endl;
    	int res=0;
    	int index = 30;
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
    		res = res + rangeBitwiseAnd(m-add,n-add) + add;
    		return res;
    	}else
    	{
    		return 0;
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
	cout<<mySolution->rangeBitwiseAnd(m,n)<<endl;
	delete mySolution;
	return 0;
}