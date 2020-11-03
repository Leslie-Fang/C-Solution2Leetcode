#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
    	vector<string> res;
    	int index = 0;
    	int compare = 0;
        bool continous = false;
        string temp = "";
        //int last = 0;
    	int length = nums.size();
    	while(index <= length-1){
    		temp = "";
    		temp += to_string(nums[index]);
    		compare = nums[index];
    		index += 1;
    		continous = false;
    		while(index <= length-1){
    			if( compare + 1 == nums[index]){
    				continous = true;
    				//last = nums[index];
    				compare = nums[index];
    				index += 1;
    			}else{
    				break;
    			}
    		}
    		if(continous){
    			temp += "->";
    			temp += to_string(compare);
    		}
    		res.push_back(temp);
    	}

    	return res;
    }
};

int main(int argc, char ** argv){
	Solution * mySolution = new Solution();
    int a[6] = {0,1,2,4,5,7};
    vector<int> input(a, a+6);
    vector<string>  res = mySolution->summaryRanges(input);
    for(auto item:res){
    	cout<<item<<endl;
    }
    delete mySolution;

	return 0;

}