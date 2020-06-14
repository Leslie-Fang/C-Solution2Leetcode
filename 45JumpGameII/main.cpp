#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        //int min = nums.size();
        bool init = false;
        queue<int> condidate;
        set<int> s;
        set<int>::iterator it;
        int last = 0;
        int size = 0;
        int cur = 0;
        int cur_max = 0;
        int step = 0;
        if(nums.size() <= 1){
            return 0;
        }
        while(1){
            if(!init){
                init = true;
                condidate.push(0);
                last = 0;
            }

            step += 1;
            size = condidate.size();
            cur_max = last;

            for(int i=0;i<size;i++){
                cur = condidate.front();
                for(int j=nums[cur];j>=1;j--){
                    if(cur+j <= last){
                        continue;
                    }else if(cur+j == nums.size()-1){
                        return step;
                    }else{
                        if(cur+j > cur_max){
                            cur_max = cur+j;
                        }
                        s.insert(cur+j);
                    }
                }
                condidate.pop();
            }
            last = cur_max;
            for(it=s.begin ();it!=s.end();it++){
                condidate.push(*it);
            }
            s.clear();
            
        }
        return step;
    }
};

int main(int argc, char ** argv)
{
	int a[5] = {2,3,0,1,4};
    //int a[5] = {1,1,1,1,1};
	vector<int> input(a,a+5);
	Solution * mySolution = new Solution();
	cout<<mySolution->jump(input)<<endl;
	delete mySolution;
	return 0;
}