#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;

        vector<int> last_val(nums.size()+1);
        //iteration(nums, k, last_val, res, 0);
        for(int deepth=1;deepth<=nums.size();deepth++)
        {
            last_val[i] = last_val[i-1] + nums[i - 1];
        }
        for(int deepth=0;deepth<nums.size();deepth++)
        {
            for(int i=deepth+1;i<=nums.size();i++)
            {
                // if(last_val[i-1] + nums[deepth] == k)
                // {
                //     res += 1;
                // }
                // last_val[i] = last_val[i-1] + nums[deepth]; 
                if (last_val[i] - last_val[deepth] == k)
                    res ++;

            }
        }
        return res;
    }
};

int main(int argc, char ** argv)
{
	// string input;
	// getline(cin, input);
	// Solution * mySolution = new Solution();
 //    cout<<mySolution->subarraySum(input)<<endl;
	// delete mySolution;
	//cout<<input<<endl;
        //     vector<int> last_val(10);
        // for(int i=0;i<last_val.size();i++)
        // {
        //     cout<<last_val[i]<<endl;
        // }
	return 0;
}