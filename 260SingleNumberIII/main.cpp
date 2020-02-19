#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
// refer to https://leetcode-cn.com/problems/single-number-iii/solution/huo-xu-wo-de-ti-jie-ke-yi-kan-dong-yi-huo-kan-zhu-/
    vector<int> singleNumber(vector<int>& nums) 
    {
        // Pass 1 : 
        // Get the XOR of the two numbers we need to find
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        // Get its last set bit
        // and with it's complementry bit
        diff &= -diff; 

        // Pass 2 :
        vector<int> rets = {0, 0}; // this vector stores the two numbers we will return
        for (int num : nums)
        {
            if ((num & diff) == 0) // the bit is not set
            {
                rets[0] ^= num;
            }
            else // the bit is set
            {
                rets[1] ^= num;
            }
        }
        return rets;
    }
};

int main(int argc, char ** argv)
{
	Solution * mySolution = new Solution();
	int input[6] = {1,2,1,3,2,5};
	vector<int> nums(input,input+6);
	vector<int> res = mySolution->singleNumber(nums);
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<endl;
	}
	delete mySolution;
	return 0;
}