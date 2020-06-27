#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = 0;
		vector<int>::iterator it=nums.begin();
		while(it < nums.end())
		{
			sum += *it;
			it = it + 2;
		}
        return sum;
    }
};

int main(int argc, char ** argv){
	int input[4] = {1,4,3,2};
	vector<int> inputs(input,input+4);
	Solution * mySolution = new Solution();
	cout<<mySolution->arrayPairSum(inputs)<<endl;
	delete mySolution;
	return 0;
}