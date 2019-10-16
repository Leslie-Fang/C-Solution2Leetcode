#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	if(nums.size() == 0)
    	{
    		return 0;
    	}
    	vector<vector<int> > res;
    	bool find = false;
    	for(int i=0;i<nums.size();i++)
    	{
    		if(res.size() == 0)
    		{
    			vector<int> temp = {nums[0]};
    			res.push_back(temp);
    		}else
    		{
    			find = false;
    			for(int j=0;j<res.size();j++)
    			{
     				if(nums[i] > res[j][res[j].size()-1])
    				{
    					find = true;
    					res[j].push_back(nums[i]);
    					continue;
    				}
    				for(int k=0;k<res[j].size()-1;k++)
    				{
    					if(nums[i] > res[j][k] && nums[i] < res[j][k+1])
    					{
    						find = true;
			    			vector<int> temp;
			    			temp.assign(res[j].begin(),res[j].begin()+k+1);
			    			temp.push_back(nums[i]);
			    			res.push_back(temp);
    					}
    				}

    			}
    			if(!find)
    			{
    				vector<int> temp = {nums[i]};
    				res.push_back(temp);
    			}
    		}

    	}
    	int max = 0;
    	for(int i=0;i<res.size();i++)
    	{
    		if(res[i].size()>max)
    		{
    			max = res[i].size();
    		}
    	}
    	return max;
    }
};

int main(){
	vector<int> input ={0};//{10,9,2,5,3,4};//{4,10,4,3,8,9};//{10,9,2,5,3,7,101,18};
	Solution * mySolution = new Solution();
	cout<<mySolution->lengthOfLIS(input)<<endl;
	delete mySolution;
	return 1;
}