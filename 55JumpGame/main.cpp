#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums);
};
bool tryJump(vector<int>& nums,int cstep);
int main(){
	int input[5] = {2,3,1,1,4};
	vector<int> inputVector(begin(input),end(input));
	Solution * mySolution = new Solution();
	cout<<mySolution->canJump(inputVector)<<endl;
	return 1;
}

bool Solution::canJump(vector<int>& nums){
	if(nums.size() == 1){
		return true;
	}
	return tryJump(nums,0);
}

bool tryJump(vector<int>& nums,int cstep){
	// for(int i=nums[cstep];i>=1;i--){
	// 	if((cstep+i)== (nums.size()-1) ){
	// 		return true;
	// 	}
	// }
	if(cstep+nums[cstep] >= (nums.size()-1)){
		return true;
	}
	bool res = false;
	for(int i=nums[cstep];i>=1;i--){
		res = res || tryJump(nums,cstep+i);
		if(res == true){
			return res;
		}
	}
	return res;
}