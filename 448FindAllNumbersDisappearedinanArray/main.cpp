#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

	void switchItem(int i, int j, vector<int>& nums)
	{
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
		return;
	}
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        bool should_loop = true;
        while(should_loop){
        	should_loop = false;
        	for(int i=0;i<nums.size();i++){
        		if(nums[i] == -1){
        			continue;
        		}else if(nums[i]-1 != i){
        			if(nums[i] != nums[nums[i]-1]){
        				should_loop = true;
        				switchItem(i, nums[i]-1, nums);
        			}else{
        				nums[i] = -1;
     				}
        		}
        	}
        }
        for(int i=0;i<nums.size();i++){
        	if(nums[i] == -1){
        		res.push_back(i+1);
        	}
        }
        return res;
    }
};

int main(int argc, char ** argv){
	Solution * mySolution = new Solution();
	int a[8] = {4,3,2,7,8,2,3,1};
	vector<int> input(a, a+8);

	vector<int> res = mySolution->findDisappearedNumbers(input);
	for(auto item : res)
	{
		cout<<item<<endl;
	}

	delete mySolution;
	return 0;
}