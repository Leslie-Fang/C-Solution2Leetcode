#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	int len = nums.size();
    	map<int,int> temp;
    	map<int,int>::iterator it;
    	if(len == 1)
    	{
    		return nums[0];
    	}
    	for(int i=0;i<len;i++)
    	{
    		it = temp.find(nums[i]);
    		if(it == temp.end())
    		{
    			temp.insert(pair<int,int>(nums[i],1));
    		}else
    		{
    			it->second += 1;
    			if(it->second > len/2 && len%2 != 0)
    			{
    				return it->first;
    			}else if(it->second >= len/2 && len%2 == 0)
    			{
    				return it->first;
    			}
    		}
    	}
    	return temp.begin()->first;
        
    }
};

int main()
{
	Solution * mySolution = new Solution();
	std::vector<int> v={2,1,1,1,2,2};
	cout<<mySolution->majorityElement(v)<<endl;
	delete mySolution;
	return 0;
}