#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    	if(nums.size() == 0)
    	{
    		return 1;
    	}
    	std::sort(nums.begin(), nums.end());
    	int i=0;
    	int j=1;
        int last = -1;
        while(nums[i] <= 0)
        {
            i++;
            if(i>=nums.size())
            {
                break;
            }
        }
    	while(i<nums.size())
    	{
            if(last != -1)
            {
                if(nums[i] == last)
                {
                    i++;
                }else if(nums[i] == j)
                {
                    last = j;
                    i++;
                    j++;
                }else
                {
                    return j;
                }
            }else
            {
                if(nums[i] != 1)
                {
                    return 1;
                }else
                {
                    last = 1;
                    j++;
                    i++;
                }
            }
    	}
    	return j;     
    }
};

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

int main(int argc, char ** argv)
{
    string input;
    getline(cin, input);
	//int a[5] = {0, 2,2,1,1};
	vector<int> inputs = getList(input);

	Solution * mySolution = new Solution();
	cout<<mySolution->firstMissingPositive(inputs)<<endl;
	delete mySolution;
	return 0;
}