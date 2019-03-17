#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void quickSort(vector<int>& nums, vector<int>::iterator begin,vector<int>::iterator end)
	{
		if(end <= begin)
		{
			return;
		}
		vector<int>::iterator it1 = begin;
		vector<int>::iterator it2 = end-1;
		int key=*begin;
		while(it1 < it2)
		{
			while(*(it2) >= key && it2 != begin)
			{
				it2 = it2 - 1;
			}
			while(*(it1) <= key && it1 != (end-1))
			{
				it1 = it1 + 1;
			}
			if(it2 > it1)
			{
				int temp=*it2;
				*it2 = *it1;
				*it1 = temp;
			}
		}
		int temp=*it2;
		*it2 = *begin;
		*begin = temp;
		quickSort(nums,begin,it2);
		quickSort(nums,it2+1,end);
		return;
	}
    bool canPartition(vector<int>& nums)
    {
    	if(nums.size() == 0)
    	{
    		return true;
    	}
    	quickSort(nums,nums.begin(),nums.end());
    	int sum = 0;
    	for(int i=0;i<nums.size();i++)
    	{
    		sum += nums[i];
    	}
    	cout<<sum<<endl;
    	if(sum %2 != 0)
    	{
    		return false;
    	}
    	return helper(nums, sum/2, 0);
    }
    bool helper(vector<int>& nums, int sum, int index){
        if(sum == nums[index]) return true;
        if(sum < nums[index]) return false;
        cout<<sum<<endl;
        return helper(nums,sum-nums[index],index+1) || helper(nums,sum,index+1);
    }
};

int main()
{
	int a[4] = {2, 2, 3, 5};
	vector<int> input(a,a+4);
	// for(vector<int>::iterator it=input.begin();it!=input.end();it++)
	// {
	// 	cout<<*it<<endl;
	// }
	Solution * mySolution = new Solution();
	cout<<mySolution->canPartition(input)<<endl;
	return 1;
}