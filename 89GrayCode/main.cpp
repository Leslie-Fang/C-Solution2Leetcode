#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
    vector<int> grayCode(int n)
    {
    	vector<int> res;
        if(n==0)
        {
        	res.push_back(0);
        	return res;
        }else
        {
        	res = subGrayCode(n);
        }
        return res;
    }
    vector<int> subGrayCode(int n)
   	{
   		vector<int> res;
   		if(n == 1)
   		{
   			res.push_back(0);
   			res.push_back(1);
   		}else
   		{
   			vector<int> temp = subGrayCode(n-1);
   			vector<int> left;
   			for(int i=0;i<temp.size();i++)
   			{
   				res.push_back(temp[i]);
   				left.push_back(pow(2,n-1)+temp[i]);
   			}
   			for(int i=left.size()-1;i>=0;i--)
   			{
   				res.push_back(left[i]);
   			}
   		}
   		return res;
   	}
};

int main(int argc,char ** argv)
{
	Solution * mySolution = new Solution();
	vector<int> res = mySolution->grayCode(11);
	for(int i=0; i<res.size();i++)
	{
		cout<<res[i]<<endl;
	}
	return 0;
}