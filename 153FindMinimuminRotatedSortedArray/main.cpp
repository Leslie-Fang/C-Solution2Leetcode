#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums);
};
int helpFindMin(vector<int>& nums,int begin, int end);
int main(int argc,char ** argv){
	Solution * mySolution = new Solution();
	int input[7]={4,5,6,7,0,1,2};
	vector<int> inputVector(begin(input),end(input));
	for(vector<int>::iterator it=inputVector.begin();it != inputVector.end();it++){
		cout<<*it<<endl;
	}
	cout<<mySolution->findMin(inputVector)<<endl;
	return 0;
}

int Solution::findMin(vector<int>& nums){
	if(nums.size() == 0){
		return 0;
	}
	if(nums[0]<nums[nums.size()-1]){
		return nums[0];
	}
	return helpFindMin(nums,0,nums.size()-1);
}

int helpFindMin(vector<int>& nums,int begin, int end){
	if(begin == end){
		return nums[begin];
	}else if((end -begin) == 1){
		if(nums[end]<nums[begin]){
			return nums[end];
		}else{
			return nums[begin];
		}

	}
	int middle = (begin+end)/2;
	//cout<<nums[middle]<<endl;
	if(nums[begin]>nums[middle]){
		return helpFindMin(nums,begin,middle);
	}else{
		return helpFindMin(nums,middle,end);
	}
	return 1;
}