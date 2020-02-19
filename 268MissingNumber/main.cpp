#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
    	int size = nums.size();
    	int s_sum = (size-1)*size/2;
    	int a_sum = 0;
    	for(int i=0;i<size;i++)
    	{
    		a_sum += nums[i];
    	}
    	return size-(a_sum-s_sum);
        
    }
};

int main(int argc, char ** argv)
{
	Solution * mySolution = new Solution();
	// int input[3] = {3,0,1};
	// vector<int> nums(input,input+3);
	int input[9] = {9,6,4,2,3,5,7,0,1};
	vector<int> nums(input,input+9);
	cout<<mySolution->missingNumber(nums)<<endl;;

	delete mySolution;
	return 0;
}