#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
    	int start = 0;
    	int sum = 0;
        while(start<nums.size())
        {
        	sum = nums[start];
        	for(int s=start+1;s<nums.size();s++)
        	{
        		sum += nums[s];
        		if(k==0)
        		{
        			if(sum == 0)
        			{
        				return true;
        			}
        		}
        		else if(sum%k == 0)
        		{
        			//cout<<sum<<endl;
        			return true;
        		}
        	}
        	start += 1;
        }
        return 0;
    }
};

int main(int argc, char ** argv){
	int inputi[5] = {23, 2, 4, 6, 7};
	vector<int> input(inputi,inputi+5);
	Solution * mySolution  = new Solution();
	cout<<mySolution->checkSubarraySum(input,18)<<endl;
	delete mySolution;
	return 1;
}