#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
    	int len = nums.size();
    	if(len == 0)
    	{
    		return 0;
    	}
    	int start = 0,end=;

    }
};

int main(int argc, char ** argv)
{
	int inputl[3] = {0,1,0};
	vector<int> input(inputl,inputl+3);
	Solution * mySolution = new Solution();
	cout<<mySolution->findMaxLength(input)<<endl;
	delete mySolution;
	return 1;
}