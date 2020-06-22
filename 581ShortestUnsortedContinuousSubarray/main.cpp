#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
	public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end());
        int i, j; i = 0; j = nums.size()-1;
        while(i < j){
            int flag = 1; 
            if(nums[i] == temp[i]){ i ++; flag = 0;} 
            if(nums[j] == temp[j]){ j --; flag = 0;}
            if(flag == 1) break; 
        }
        if(i >= j) return 0;
        return j-i+1;
    }
};


int main(int argc, char ** argv)
{
	int a[7] = {2, 6, 4, 8, 10, 9, 15};
	vector<int> input(a, a+7);
	Solution * mySolution;
	cout<<mySolution->findUnsortedSubarray(input)<<endl;
	return 0;
}