#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //快慢指针法，重复的这个元素值，作为数组的索引就是环的入口
        int slow = 0;
        int fast = 0;
        do {
        	slow = nums[slow];
        	fast = nums[nums[fast]];
        }while(slow != fast);
        slow = 0;
        do {
        	slow = nums[slow];
        	fast = nums[fast];
        }while(slow != fast);

        return fast;
    }
};

int main(int argc, char ** argv){
	Solution * mySolution = new Solution();
	int a[5] = {1,3,4,2,2};
	vector<int> input(a, a+5);

	cout<<mySolution->findDuplicate(input)<<endl;

	delete mySolution;
	return 0;
}