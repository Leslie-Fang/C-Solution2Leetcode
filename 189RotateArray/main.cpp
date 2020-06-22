#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int i = 0, j = 0;
        while(k>=nums.size()){
        	k = k - nums.size();
        }
        int m = nums.size() - k;
        int tmp = 0;
        while(m>0){
        	tmp = *nums.begin();
        	nums.push_back(tmp);
        	nums.erase(nums.begin());
        	m--;
        }

        return;
    }
};

int main(int argc, char ** argv){
	int a[7] = {1,2,3,4,5,6,7};
	vector<int> input(a, a+7);

	Solution * mySolution = new Solution();
	mySolution->rotate(input, 3);

	for(auto item:input){
		cout<<item<<endl;
	}

	return 0;
}