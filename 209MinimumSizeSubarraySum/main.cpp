#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    	//vector<int> temp;
    	int res = 0;
    	int sub_res = 0;
    	int sum = 0;
    	int start =0, end =0;
    	for(int i=0;i<nums.size();i++)
    	{
    		if(sum>=s)
    		{
    		   	sum += nums[i];
	    		sub_res += 1;	
	    		end += 1;
	    		while(1)
	    		{
	    			if(sum - nums[start] >= s)
	    			{
	    				sum = sum - nums[start];
	    				start += 1;
	    				sub_res -= 1;	
	    			}else
	    			{
	    				break;
	    			}
	    		}
	    		if(sub_res < res)
	    		{
	    			res = sub_res;
	    		}
    		}else
    		{
    			sum += nums[i];
	    		res += 1;
	    		sub_res += 1;
	    		end += 1;
    		}
    	}
    	if(end-start != 0)
    	{
    		while(1)
		    {
		    	if(sum - nums[start]>= s)
		    	{
		    		sum = sum - nums[start];
		    		start += 1;
		    		res -= 1;	
		    	}else
		    	{
		    		break;
		    	}
		    }
    	}
    	if(sum < s)
    	{
    		return 0;
    	}
    	return res;
        
    }
};

int main()
{
	Solution * mySolution = new Solution();
	vector<int> input = {};
	cout<<mySolution->minSubArrayLen(11,input)<<endl;
	delete mySolution;
	return 0;
}