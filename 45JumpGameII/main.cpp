#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> exclude_list;
        if(nums.size() == 1)
        {
            return 0;
        }

        int target_index = nums.size()-1;
        vector<int> backup_index_list;
        backup_index_list.push_back(nums.size()-1);
        int base = 0;
        exclude_list.push_back(nums.size()-1);

        while(1)
        {
            vector<int> temp(backup_index_list);
            backup_index_list.clear();
            // cout<<"start a new round"<<endl;
            for(int i=0;i<temp.size();i++)
            {
                int target_index = temp[i];
                //cout<<target_index<<endl;
                if(nums[0] >= target_index)
                {
                    return base+1;
                }
                for(int j=target_index-1;j>=0;j--)
                {
                    if(nums[j]+j >= target_index)
                    {
                        // cout<<"hit"<<endl;
                        // cout<<j<<endl;
                        if(find(exclude_list.begin(), exclude_list.end(), j) == exclude_list.end())
                        {
                            // cout<<"push_bakc"<<endl;
                            // cout<<j<<endl;
                            backup_index_list.push_back(j);
                            exclude_list.push_back(j);
                        }
                    }
                }
            }
            base += 1;
        }

        return 0;
    }
};

int main(int argc, char ** argv)
{
	int a[5] = {2,3,0,1,4};
	vector<int> input(a,a+5);
	Solution * mySolution = new Solution();
	cout<<mySolution->jump(input)<<endl;
	delete mySolution;
	return 0;
}