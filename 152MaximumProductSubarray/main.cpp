#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
    	int res = 0;
    	if(nums.size()>=0)
    	{
    		int tmin = nums[0];
    		int tmax = nums[0];
    		int pre_max = nums[0];
    		int pre_min = nums[0];
            res = nums[0];
    		for(int i=1;i<nums.size();i++)
	    	{
	    		tmax = max(max(pre_max*nums[i],pre_min*nums[i]),nums[i]);
	    		tmin = min(min(pre_max*nums[i],pre_min*nums[i]),nums[i]);
                res = max(res,tmax);
                pre_max = tmax;
                pre_min = tmin;
	    	}
	    	//res = max;
    	}
        return res;
    }
};

int main()
{

	return 0;
}