#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums);
};

int main(int argc, char ** argv){
	//cout<<argv[0]<<endl;
	int input[10]={0,0,1,1,1,2,2,3,3,4};
	vector<int> inputVector(begin(input),end(input));
	for(vector<int>::iterator it=inputVector.begin();it!=inputVector.end();it++){
		cout<<*it<<endl;
	}
	Solution * mySolution = new Solution();
	mySolution->removeDuplicates(inputVector);
	cout<<"<-------------------->"<<endl;
	for(vector<int>::iterator it=inputVector.begin();it!=inputVector.end();it++){
		cout<<*it<<endl;
	}
	return 1;
}

int Solution::removeDuplicates(vector<int>& nums){
	int len = nums.size();
	if(len <= 1){
		return len;
	}
	int preNum = nums[0];
	int res = 1;
	int point = 1;
	for(int i=1;i<len;i++){
		if(nums[i] != preNum){
			preNum = nums[i];
			nums[point] = nums[i];
			point ++;
			res ++;
		}
	}
	return res;
}