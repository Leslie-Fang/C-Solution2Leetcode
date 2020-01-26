#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void dfs(vector<int>& nums, int & subset_l, int index, vector<int>& temp, vector<vector<int>>& res,
		int & last_ele){
		if(temp.size() >= subset_l)
		{
			res.push_back(temp);
			last_ele = temp.back();
			cout<<"pop_back: "<<last_ele<<endl;
			temp.pop_back();
			return;
		}
		for(int i=index;i<nums.size();i++)
		{
			if(last_ele != nums[i])
			{
				cout<<"push_back: "<<nums[i]<<endl;
				temp.push_back(nums[i]);
				dfs(nums, subset_l, i+1, temp, res, last_ele);
			}else
			{
				continue;
			}
		}
		if(temp.size() >= 1)
		{
			last_ele = temp.back();
			cout<<"pop_back: "<<last_ele<<endl;
			temp.pop_back();
		}
		return;
	}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int>> res;
        res.push_back(temp);
        int last_ele;
        for(int subset_l = 1;subset_l<=nums.size();subset_l++)
        {
        	cout<<"subset_l: "<<subset_l<<endl;
        	temp.clear();
        	last_ele = -1887;
			dfs(nums, subset_l, 0, temp, res, last_ele);
        }
        return res;
    }
};

int main(){
	Solution * mySolution = new Solution();
	vector<int> input;
	input.push_back(0);
	mySolution->subsetsWithDup(input);
	delete mySolution;
	return 0;
}