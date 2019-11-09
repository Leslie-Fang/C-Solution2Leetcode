#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        //sort(nums.begin(), nums.begin() +nums.size());
        vector<pair<int, int>>dup;
        for(int i=0; i<nums.size();i++){
            dup.push_back(make_pair(nums[i],i));
        }
        sort(dup.begin(), dup.end());
        for(int i=0; i<nums.size();i++){
            for(int j=i+1; j<nums.size();j++){
                if(dup[i].first+t>=dup[j].first){
                   if(abs(dup[i].second-dup[j].second)<=k){
                        return true;
                   } 
                }
                else{
                    break;
                }
                
            }
        }
        return false;
    }
};

int main(int argc, char ** argv){
	vector<int> input = {1,5,9,1,5,9};
	Solution * mySolution = new Solution();
	cout<<mySolution->containsNearbyAlmostDuplicate(input,2,3)<<endl;
	delete mySolution;
	return 0;

}