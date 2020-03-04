#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool subwordBreak(string & s, vector<string>& wordDict, int index, vector<bool> & memory)
	{
		if(index >= s.length())
		{
			return true;
		}
		bool res = false;
		int step = 0;
		memory[index] = true;
		for(int i=0;i<wordDict.size();i++)
		{
			step = wordDict[i].size();
			if(index+step <= s.length())
			{
				if(memory[index+step])
				{
					continue;
				}
				if(s.substr(index,step) == wordDict[i])
				{
					res = res || subwordBreak(s, wordDict, index+step, memory);
					if(res)
					{
						return res;
					}
				}
			}
		}
		return res;
	} 
    bool wordBreak(string s, vector<string>& wordDict) {
    	vector<string> wordDict2;
    	while(wordDict.size() > 0)
    	{
    		int max = 0;
    		vector<string>::iterator it = wordDict.begin();
    		for(vector<string>::iterator it2 = wordDict.begin();it2<wordDict.end();it2++)
    		{
    			if((*it2).length() >= max)
    			{
    				max = (*it2).length();
    				it = it2;
    			}
    		}
    		wordDict2.push_back(*it);
    		wordDict.erase(it);
    	}
    	// int ll = s.length();
    	// bool[ll] memory;
    	vector<bool> memory(s.size(), false);
        return subwordBreak(s, wordDict2, 0, memory);
    }
};


int main(int argc, char ** argv)
{
	string input[5] = {"cats", "dog", "sand", "and", "cat"};
	vector<string> vInput(input,input+5);
	string target = "catsandog";
	Solution * mySolution = new Solution();
	cout<<mySolution->wordBreak(target, vInput)<<endl;
	delete mySolution;
	return 0;
}