#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    	int begin = 0;
    	int end = nums.size()-1;
    	int length = end - begin + 1;
    	int half_index = length/2;
    	while(end > begin)
    	{
    		length = end - begin + 1;
    		half_index = length/2+begin;
    		if(half_index%2 == 0)
    		{
    			if(nums[half_index] == nums[half_index-1])
    			{
    				end = half_index-2;
    			}else if(nums[half_index] == nums[half_index+1]){
    				begin = half_index + 2;
    			}else{
    				return nums[half_index];
    			}
    		}else{
    			if(nums[half_index] == nums[half_index-1])
    			{
    				begin = half_index + 1;
    			}else if(nums[half_index] == nums[half_index+1]){
    				end = half_index-1;
    			}else{
    				return nums[half_index];
    			}
    		}
    	}
    	return nums[begin];
    }
};

int main(int argc, char ** argv){
	int a[7] = {3,3,7,7,10,11,11};
	vector<int> input(a,a+9);
	Solution * mySolution = new Solution();
	cout<<mySolution->singleNonDuplicate(input)<<endl;
	delete mySolution;
	return 1;
}