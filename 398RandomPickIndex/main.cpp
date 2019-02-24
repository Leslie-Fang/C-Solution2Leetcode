#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    Solution(vector<int> nums) {
        for(int i = 0; i < nums.size(); ++i)
            hash[nums[i]].push_back(i); 
    }
   
    int pick(int target){
    	vector<int> temp = hash[target];
        int index = rand() % temp.size();
        return temp[index];

    }

private:
	unordered_map<int,vector<int>>hash;
};


int main(int argc,char ** argv)
{
	//cout<<"Hello World!"<<endl;
	int nums[5] = {1,2,3,3,3};
	vector<int> inputnums(nums,nums+5);
	Solution * solution = new Solution(inputnums);
	cout<<solution->pick(1)<<endl;
	return 0;
}
