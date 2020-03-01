#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
        //cout<<res[i]<<endl;
        res2.push_back(stoi(res[i]));
    }
    return res2;
}

class Solution {
public:
    int trap(vector<int>& height) {
    	int res = 0;
    	//vector<int> temp;
    	int leftmax = 0, rightmax = 0, last = 0;
    	int rightmax_index = 0;
    	//bool first = true;
    	int temp = 0, temp_height = 0;
    	for(int i=0;i<height.size();i++)
    	{
    		if(height[i] >= leftmax)
    		{
    			leftmax = height[i];
    		}
    		if(i >= rightmax_index)
    		{
    			rightmax_index = i;
	    		rightmax = height[i];
	    		temp = i;
	    		while(temp <= height.size()-1)
	    		{
	    			if(height[temp] >= rightmax)
	    			{
	    				rightmax = height[temp];
	    				rightmax_index = temp;
	    			}
	    			temp += 1;
	    		}
    		}
    		temp_height = leftmax<rightmax?leftmax:rightmax;
    		res += temp_height<height[i]?0:temp_height-height[i];
    	}
    	//cout<<res<<endl;
    	//res += calculateVolume(temp);
        return res;
    }
};

int main(int argc, char ** argv)
{
    string input;
    getline(cin, input);
	//int a[5] = {0, 2,2,1,1};
	vector<int> inputs = getList(input);

	Solution * mySolution = new Solution();
	cout<<mySolution->trap(inputs)<<endl;
	delete mySolution;
	return 0;
}