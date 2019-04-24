#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums)
    {
    	vector<vector<int> > res;
    	vector<int> empty;
    	res.push_back(empty);
    	sub_subsets(empty, nums, res);
    	return res;
    }
    void sub_subsets(vector<int> temp_nums, vector<int> nums, vector<vector<int> > & res)
    {
    	if(nums.size() == 0)
    	{
    		return;
    	}
    	vector<int> temp = nums;
    	vector<int> temp_set = temp_nums;
    	for(vector<int>::iterator it = nums.begin(); it != nums.end();it ++)
    	{
    		temp = nums;
    		temp_set = temp_nums;
    		bool stop = false;
    		for(vector<int>::iterator it2 = temp_set.begin(); it2 != temp_set.end();it2 ++)
    		{
    			if(*it < *it2)
    			{
    				stop = true;
    				break;
    			}
    		}
    		if(stop)
    		{
    			continue;
    		}
    		temp_set.push_back(*it);
    		res.push_back(temp_set);
    		int val = *it;
    		temp.erase(std::find(temp.begin(),temp.end(),val));
    		sub_subsets(temp_set,temp,res);
    	}
    	return;
    }
};

int main(int argc,char ** argv)
{
	cout<<"Hello World"<<endl;
	Solution * mySolution = new Solution();
	vector<int> input;
	input.push_back(1);
	input.push_back(2);
	input.push_back(3);
	mySolution->subsets(input);
	delete mySolution;
	return 0;
}