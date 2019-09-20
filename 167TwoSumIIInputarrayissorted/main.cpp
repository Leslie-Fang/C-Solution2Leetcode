#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    	vector<int> res;
    	for(int i=0;i<numbers.size();i++)
    	{
    		res.clear();
    		res.push_back(i+1);
    		for(int j=i+1;j<numbers.size();j++)
    		{
    			if(numbers[i] + numbers[j] == target)
    			{
    				res.push_back(j+1);
    				return res;
    			}else if(numbers[i] + numbers[j] > target)
    			{
    				break;
    			}
    		}
    	}
    	return res;  
    }
};

int main(int argc, char ** argv)
{
	vector<int> input={2,7,11,15};
	Solution * mySolution = new Solution();
	vector<int> res = mySolution->twoSum(input,9);
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<endl;
	}
	delete mySolution;

	return 1;
}