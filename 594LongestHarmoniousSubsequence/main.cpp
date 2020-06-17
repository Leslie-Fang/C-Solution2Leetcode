#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
    	if(nums.size() == 0){
    		return 0;
    	}
    	
    	sort(nums.begin(), nums.end());
    	int cur = nums[0];
    	int last = nums[0];
    	int count[2] = {0, 0};
    	int count_data[2] = {nums[0], nums[0]};
    	int index = 0;
    	int res = 0;
    	for(auto data:nums){
    		cur = data;
    		if(cur == last){
    			count[index] ++;
    		}else{
    			if(index == 0){
    				index = 1;
    				count_data[1] = data;
    			}else{
    				if(count_data[1]-count_data[0] == 1 && count[0]+count[1] > res){
    					res = count[0]+count[1];
    				}
    				count[0] = count[1];
    				count[1] = 0;
    				count_data[0] = count_data[1];
    				count_data[1] = data;
    				index = 1;
    			}
    			count[index] ++;
    		}
    		last = data;
    	}
    	if(count_data[1]-count_data[0] == 1 && count[0]+count[1] > res){
    		res = count[0]+count[1];
    	}

    	return res;
    }
};

int main(int argc, char ** argv){
	return 0;
}