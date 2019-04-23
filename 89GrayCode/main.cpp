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
        	// vector<int> temp = subGrayCode(n);
        	// for(int i=0;i<temp.size();i++)
        	// {
        	// 	cout<<temp[i]<<endl;
        	// 	res.push_back(two2ten(temp[i]));
        	// }
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
    // int two2ten(int input)
    // {
    // 	int result = 0;
    // 	int index  = 0;
    // 	while(input != 0)
    // 	{
    // 		result += (input % 10)*pow(2,index);
    // 		index += 1;
    // 		input = input / 10;
    // 	}
    // 	return result;
    // }
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