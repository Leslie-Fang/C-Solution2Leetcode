#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
		if(needle.length() == 0)
    	{
    		return 0;
    	}
    	for(int i=0;i<haystack.length();i++)
    	{
    		int k=0;
    		while(k<needle.length() && i+k < haystack.length())
    		{
    			if(haystack[i+k] == needle[k])
    			{
    				k++;
    			}else
    			{
    				break;
    			}
    		}
    		if(k == needle.length())
    		{
    			return i;
    		}
    	}
        return -1;
    }
};

int main(int argc, char ** argv)
{
	string input,needle;
	getline(cin, input);
	getline(cin, needle);
	Solution * mySolution = new Solution();
	cout<<mySolution->strStr(input,needle)<<endl;
	delete mySolution;
}