#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums);
};
int main(int argc, char ** argv){
	cout<<"hello"<<endl;
	Solution * mySolution = new Solution();
	int a[4] = {1,2,3,1};
	vector<int> b;
	b.insert(b.begin(), a, a+4);
	cout<<mySolution->findPeakElement(b)<<endl;
	return 1;
}

int Solution::findPeakElement(vector<int>& nums){
	if(nums.size()==0 || nums.size()==1){
		return 0;
	}else if(nums[0] > nums[1]){
		return 0;
	}else if(nums[nums.size()-1] > nums[nums.size()-2]){
		return nums.size()-1;
	}else{
		int i=1;
		while(i<nums.size()-1){
			if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
				return i;
			}
			i++;
		}
	}
	return 0;
}
