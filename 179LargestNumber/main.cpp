#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
    	if(nums.size() == 0)
    	{
    		return "";
    	}else if(nums.size() == 1)
    	{
    		return to_string(nums[0]);
    	}
    	auto cmp = [](const int &at, const int &bt)
    	{
    		string a = to_string(at);
    		string b = to_string(bt);
	    	int i=0;
	         while(1)
	         {
	         	if(i<a.size() && i < b.size())
	         	{
	         		if( int(a[i]) > int(b[i]))
	         		{
	         			return false;
	         		}else if(int(a[i]) < int(b[i]))
	         		{
	         			return true;
	         		}
	         	}else
	         	{
	         		if(i == a.size())
	         		{
	         			if(b[i] > a[0])
	         			{
							return true;
	         			}else if(b[i] < a[0])
	         			{
	         				return false;
	         			}else
	         			{
	         				for(int j=i-1;j>=0;j--)
	         				{
	         					if(b[i] > b[j])
	         					{
	         						return true;
	         					}else if(b[i] < b[j])
	         					{
	         						return false;
	         					}
	         				}
	         				return false;
	         			}
	         		}else
	         		{
	         			if(a[i] > b[0])
	         			{
							return false;
	         			}else if(a[i] < b[0])
	         			{
	         				return true;
	         			}else
	         			{
	         				for(int j=i-1;j>=0;j--)
	         				{
	         					if(a[i] > a[j])
	         					{
	         						return false;
	         					}else if(a[i] < a[j])
	         					{
	         						return true;
	         					}
	         				}
	         				return true;
	         			}
	         		}
	         	}
	         	i += 1;
	         }
	         return false;
    	};
    	
    	string res="";
    	int lent = nums.size();
    	for(int i=0;i<lent;i++)
    	{
    		make_heap(nums.begin(), nums.end(), cmp);
    		res += to_string(nums.front());
    		pop_heap(nums.begin(), nums.end());
    		nums.pop_back();
    	}
    	// for(int i=0;i<res.size;i++)
    	// {
    	// 	if(res[i] == '0' && i==res.size()-1)
    	// 	{
    	// 		res = "0";
    	// 		break;
    	// 	}
    	// }
    	if(res[0] == '0')
    	{
    		res = "0";
    	}
    	return res;
        
    }
};

int main(int argc, char ** argv)
{
	vector<int> input = {999999998,999999997,999999999};
	Solution * mySolution = new Solution();
	cout<<mySolution->largestNumber(input)<<endl;
	delete mySolution;
	return 1;
}