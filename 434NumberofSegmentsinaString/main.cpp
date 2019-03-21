#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
    	int res = 0;
    	if(s.size() == 0)
    	{
    		return res;
    	}
        for(int i=0;i<s.size();i++)
        {
        	if(int(s[i])==32)
        	{
        		if(i==0)
        		{
        			continue;
        		}
        		else if(int(s[i-1])==32)
        		{
        			continue;
        		}else
        		{
        			res = res + 1;
        		}
        	}
        }
        if(int(s[s.size()-1]) != 32)
        {
        	res = res + 1;
        }
        return res;
    }
};

int main()
{
	string input = "  Hello, my   ame is John ";
	Solution * mySolution = new Solution();
	cout<<mySolution->countSegments(input)<<endl;
	return 0;
}