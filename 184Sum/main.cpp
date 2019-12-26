#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> first;
        vector<int> second;
        vector<int> thrid;
        vector<int> forth;
        sort(nums.begin(), nums.end());
        int length = nums.size();
        for(int i=0;i<length-3;i++)
        {
            for(int j=i+1;j<length-2;j++)
            {
                for(int k=j+1;k<length-1;k++)
                {
                    for(int m=k+1;m<length;m++)
                    {
                        if(nums[i]+nums[j]+nums[k]+nums[m] == target)
                        {
                            bool find = false;
                            bool duplicate = false;
                            for(int n=0;n<first.size();n++)
                            {
                                if(first[n] == nums[i])
                                {
                                    find = true;
                                    if(second[n] == nums[j]
                                        && thrid[n] == nums[k]
                                        && forth[n] == nums[m])
                                    {
                                        duplicate = true;
                                    }
                                }
                            }
                            cout<<"find:"<<find<<endl;
                            cout<<"duplicate:"<<duplicate<<endl;
                            if(find == false || (find == true && duplicate == false))
                            {
                                first.push_back(nums[i]);
                                second.push_back(nums[j]);
                                thrid.push_back(nums[k]);
                                forth.push_back(nums[m]);
                            }
                        }
                    }
                }
            }
        }
        for(int n=0;n<first.size();n++)
        {
            vector<int> temp;
            temp.push_back(first[n]);
            temp.push_back(second[n]);
            temp.push_back(thrid[n]);
            temp.push_back(forth[n]);
            res.push_back(temp);
        }
        return res;
    }
};

int main(int argc, char ** argv){
	int input[6] = {1, 0, -1, 0, -2, 2};
	vector<int> inputs(input,input+6);
	Solution * mySolution = new Solution();
	mySolution->fourSum(inputs, 0);
	delete mySolution;
	return 0;
}