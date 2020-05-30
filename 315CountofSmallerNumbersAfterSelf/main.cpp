#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
    	int count = 0;
    	bool find = false;
  		if(nums.size()<=0){
  			return nums;
  		}
    	vector<int> res;
    	vector<int>::iterator it;
    	vector<int> temp;
    	res.push_back(0);
    	temp.push_back(nums[nums.size()-1]);
    	for(int i=nums.size()-2;i>=0;i--){
    		it = lower_bound(temp.begin(),temp.end(),nums[i]);
    		//计算两个iterator之间的距离
    		count = distance(temp.begin(), it);
    		if(it == temp.end()){
				temp.push_back(nums[i]);
    		}else{
    			temp.insert(it,nums[i]);
    		}
    		res.insert(res.begin(), count);
    	}
    	//vector<int> res2(begin(res), end(res));
    	return res; 
    }
};

int main(int argc, char ** argv){
	Solution * mySolution = new Solution();
	int a[4] = {5,2,6,1};
	vector<int> input(a, a+4);
	vector<int> res = mySolution->countSmaller(input);
	for(auto item : res){
		cout<<item<<endl;
	}
	delete mySolution;
	return 0;
}