#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int min = nums.size();
        DP(min, 0, 0, nums, nums.size());
        return min;
    }

    void DP(int & min, int index, int cur_steps, vector<int>& nums, const int& length){
        if(index >= length){
            return;
        }else if(index == length-1){
            if(cur_steps <= min){
                min = cur_steps;
            }
            return;
        }
        for(int i=1;i<=nums[index];i++){
            if(cur_steps+1>=min){
                break;
            }
            DP(min, index+i, cur_steps+1, nums, length);
        }
        return;
    }
};

int main(int argc, char ** argv)
{
	int a[5] = {2,3,0,1,4};
    //int a[5] = {1,1,1,1,1};
	vector<int> input(a,a+5);
	Solution * mySolution = new Solution();
	cout<<mySolution->jump(input)<<endl;
	delete mySolution;
	return 0;
}