#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
    	if(nums.size() < 3)
    	{
    		return false;
    	}
    	int len = nums.size();
    	int min = nums[0];
    	for(int i=0;i<len;i++)
    	{
    		min = min<nums[i]?min:nums[i];
    		if(min == nums[i])
    		{
    			continue;
    		}
    		for(int k=i+1;k<len;k++)
    		{
    			if(nums[k]>min && nums[k]<nums[i])
    			{
    				return true;
    			}
			}
    	}
    	return false;
    }
};

int main()
{
	int inputn[4] = {1, 2, 3, 4};
	vector<int> input(inputn,inputn+4);
	Solution * mySolution = new Solution();
	cout<<mySolution->find132pattern(input)<<endl;
	delete mySolution;
	return 1;
}