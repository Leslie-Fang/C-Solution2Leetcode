#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs);
};

int main(int argc,char** argv){
	vector<string> input;
	input.push_back("dog");
	input.push_back("racecar");
	input.push_back("car");
	// input.push_back("flower");
	// input.push_back("flow");
	// input.push_back("flight");
	Solution * mySolution = new Solution();
	cout<<mySolution->longestCommonPrefix(input)<<endl;
	delete mySolution;
	return 0;
}
string Solution::longestCommonPrefix(vector<string>& strs){
	string res  = "";
	if(strs.size() == 0)
	{
		return res;
	}
	int min_length = strs[0].length();
	for(int i=0;i<strs.size();i++)
	{
		if(min_length < strs[i].length())
		{
			min_length = strs[i].length();
		}
	}
	if(min_length == 0)
	{
		return res;
	}
	int index = 0;
	char judge = strs[0][index];
	bool shouldContinue = true;
	while(shouldContinue)
	{
		for(int i=0;i<strs.size();i++)
		{
			if(strs[i][index] != judge)
			{
				shouldContinue =false;
				break;
			}
		}
		if(shouldContinue)
		{
			res += judge;
			index += 1;
			if(index == min_length)
			{
				break;
			}
			judge = strs[0][index];
		}
	}
	return res;

}