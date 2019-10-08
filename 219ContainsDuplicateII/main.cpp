#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    	map<int, int> mymap;
    	map<int, int>::iterator it;
    	for(int i=0;i<nums.size();i++)
    	{
    		it = mymap.find(nums[i]);
    		if( it == mymap.end())
    		{
    			mymap.insert(pair<int, int>(nums[i],i));
    		}else
    		{
    			if(abs(it->second - i) <= k)
    			{
    				return true;
    			}else
    			{
    				it->second = i;
    			}
    		}
    	}
        return false;
    }
};

int main(int argc, char ** argv){
	vector<int> input = {1,2,3,1,2,3};
	Solution * mySolution = new Solution();
	cout<<mySolution->containsNearbyDuplicate(input,2)<<endl;
	delete mySolution;
	return 0;

}