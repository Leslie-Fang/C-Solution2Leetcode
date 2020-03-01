#include <iostream>
#include <vector>
using namespace std;

	void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
	{
	  std::string::size_type pos1, pos2;
	  pos2 = s.find(c);
	  pos1 = 0;
	  while(std::string::npos != pos2)
	  {
	    v.push_back(s.substr(pos1, pos2-pos1));
	 
	    pos1 = pos2 + c.size();
	    pos2 = s.find(c, pos1);
	  }
	  if(pos1 != s.length())
	    v.push_back(s.substr(pos1));
	}

vector<int> getList(string input)
{
	vector<string> res;
	SplitString(input, res, ",");
	vector<int> res2;
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<endl;
		res2.push_back(stoi(res[i]));
	}
	return res2;
}

class Solution {
public:
	bool subSearch(vector<int>& nums, int target, int start, int end, vector<int> &res)
	{
		if(start > end)
		{
			return false;
		}
		int mid = (end-start)/2 + start;
		if(nums[mid] == target)
		{
			int temp = mid;
			while(nums[temp] == target )
			{
				temp --;
				if(temp < start)
				{
					break;
				}
			}
			res.push_back(temp+1);
			temp = mid;
			while(nums[temp] == target)
			{
				temp ++;
				if(temp > end)
				{
					break;
				}
			}
			res.push_back(temp-1);
			return true;
		}else if(nums[mid] < target)
		{
			return subSearch(nums, target, mid+1, end, res);
		}else
		{
			return subSearch(nums, target, start, mid-1, res);
		}
	}
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        bool find = subSearch(nums, target, 0, nums.size()-1, res);
        if(!find)
        {
        	res.push_back(-1);
        	res.push_back(-1);
        }
        return res;
    }
};

int main(int argc, char ** argv){
	string input, input2;
	getline(cin, input);
	getline(cin, input2);
	vector<int> inputV = getList(input);

	Solution * mySolution = new Solution();
	vector<int> res = mySolution->searchRange(inputV, stoi(input2));

	cout<<"--------print result------------"<<endl;
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<endl;
	}
	delete mySolution;
	return 0;

}