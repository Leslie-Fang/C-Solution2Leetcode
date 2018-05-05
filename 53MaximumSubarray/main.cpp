#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums);
};
void goUntilePositive(vector<int>& nums,int & point, int & sum);
int main(int argc,char ** argv){
	int input[9] = {-2,1,-3,4,-1,2,1,-5,4};
	vector<int> inputVector(begin(input),end(input));
	Solution * mySolution = new Solution();
	cout<<mySolution->maxSubArray(inputVector)<<endl;
	return 1;

}

int Solution::maxSubArray(vector<int>& nums){
	int sum=0;
	int point=0;
	int length=nums.size();
	int csum =sum;
	int cmin = nums[0];
	while(nums[point]<=0){
		if(nums[point]>cmin){
			cmin = nums[point];
		}
		point++;
		if(point >= length){
			return cmin;
		}
	}
	while(1){
		if(point >= length){
				break;
		}
		while(nums[point] >= 0){
			sum +=nums[point];
			point++;
			if(point >= length){
				if(sum > csum){
					return sum;
				}else{
					return csum;
				}
			}
		}
		if(sum > csum){
			csum = sum;
		}
		goUntilePositive(nums,point,sum);
	}
	return csum;
}

void goUntilePositive(vector<int>& nums,int & point, int & sum){
	int tempSum = sum;
	int length=nums.size();
	while(nums[point] <= 0){
		tempSum +=nums[point];
		point ++;
		if(point >= length){
			return;
		}
	}
	if(tempSum < 0){
		sum = 0;
	}else{
		sum = tempSum;
	}
	return;
}