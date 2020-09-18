#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

	void insert(vector<int>& a, int num){
		bool find = false;
		for(vector<int>::iterator it=a.begin();it != a.end();it++){
			if(num > *it){
				a.insert(it, num);
				find = true;
				break;
			}
		}
		if(!find){
			a.push_back(num);
		}
    	if(a.size() > 3){
    		a.pop_back();
    	}
    	return;
	}

    int thirdMax(vector<int>& nums) {
    	if(nums.size() <= 0){
    		return 0;
    	}
    	vector<int> a;
    	a.push_back(nums[0]);
    	bool exsit = false;
    	for(int i=0;i<nums.size();i++){
    		exsit = false;
    		for(int j=0;j<a.size();j++){
    			if(nums[i] == a[j]){
    				exsit = true;
    				break;
    			}
    		}
    		if(exsit){
    			continue;
    		}
    		insert(a, nums[i]);
    	}
    	return a.size()==3?a[2]:a[0];  
    }
};

int main(int argc, char ** argv){
	Solution * mySolution = new Solution();
	//int a[3] = {3, 2, 1};
	int a[2] = {2, 1};
	vector<int> vinput(a, a+2);
	cout<<mySolution->thirdMax(vinput)<<endl;
	return 0;
}