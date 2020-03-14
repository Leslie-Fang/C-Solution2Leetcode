#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        vector<int> L(nums.size(), 1);
        vector<int> R(nums.size(), 1);
        for(int i=1;i<nums.size();i++)
        {
        	L[i] = L[i-1] * nums[i-1];
        	R[nums.size()-1-i] = R[nums.size()-i] * nums[nums.size()-i];
        }
        for(int i=0;i<nums.size();i++)
        {
        	res.push_back(L[i] * R[i]);
        }
        return res;
    }
};

int main(int argc, char ** argv)
{
	int input[4] = {1,2,3,4};
	vector<int> vInput(input,input+4);
	Solution * mySolution = new Solution();
	vector<int> res = mySolution->productExceptSelf(vInput);
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<endl;
	}
	delete mySolution;
	return 0;

}