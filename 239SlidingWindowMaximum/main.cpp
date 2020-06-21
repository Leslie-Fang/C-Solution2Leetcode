#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    	vector<int> res;
    	int tmp_max_index = 0;
    	int index = 0;
    	int tmp_max = nums[0];
    	while(index < nums.size()){
    		if(index < k){
    			if(nums[index] > tmp_max){
    				tmp_max = nums[index];
    				tmp_max_index = index;
    			}
    		}else{
    			if(tmp_max_index > index-k){
    				if(nums[index] > tmp_max){
    					tmp_max = nums[index];
    					tmp_max_index = index;
    				}
    			}else{
    				tmp_max = nums[index-k+1];
					tmp_max_index = index-k+1;
					for(int i=index-k+1;i<=index;i++){
						if(nums[i]>tmp_max){
							tmp_max = nums[i];
							tmp_max_index = i;
						}
					}
    			}
    		}
    		if(index >= k-1){
    			res.push_back(tmp_max);
    		}
    		index += 1;
    	}
    	return res;
    }
};

int main(int argc, char ** argv){

	return 0;
}