#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums);
    bool tryJump(vector<int>& nums,int pos,int len);
    bool tryJump2(vector<int>& nums,int pos);
    bool canJump2(vector<int>& nums, int from,int to);
};
int main(){
	int input[5] = {3,2,1,0,4};
	vector<int> inputVector(begin(input),end(input));
	Solution * mySolution = new Solution();
	cout<<mySolution->canJump(inputVector)<<endl;
	return 1;
}

bool Solution::canJump(vector<int>& nums){
	//return tryJump(nums,0,0);
	return tryJump2(nums,nums.size()-1);
}
bool Solution::tryJump(vector<int>& nums,int pos,int len)
{
	cout<<"----cpos is: "<<pos<<" step is: "<<len<<endl;
	if(pos+len >= nums.size())
	{
		return false;
	}else if(pos+len == nums.size()-1)
	{
		return true;
	}else
	{
		int cpos = pos+len;
		cout<<"cpos is: "<<cpos<<endl;
		for(int i=nums[cpos];i>=1;i--)
		{
			cout<<"cpos is: "<<cpos<<endl;
			cout<<"cpos is: "<<cpos<<" step is: "<<i<<endl;
			if(nums.size() <= cpos+i)
			{
				return true;
			}
			if(tryJump(nums,cpos,i))
			{
				return true;
			}
			//exit(1);
		}
	}
	return false;

}

bool Solution::tryJump2(vector<int>& nums,int pos)
{
	for(int i=pos-1;i>=0;i--)
	{
		if(i+nums[i] >= pos)
		{
			cout<<"pos is : "<<pos<<endl;
			if(i==0)
			{
				return true;
			}
			return tryJump2(nums,i);
		}
	}
	return false;
}

