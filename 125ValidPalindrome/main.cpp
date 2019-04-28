#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
    	if(s.length() <= 1)
    	{
    		return true;
    	}
    	//std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    	int count = 0;
    	string temp = "";
    	for(int i=0;i<s.length();i++)
    	{
    		if((int(s[i]<=90 && int(s[i]>=65))))
    		{
    			count++;
				temp += char(int(s[i])+32);
    		}
    		if( (int(s[i]<=57 && int(s[i]>=48))) || (int(s[i]<=122 && int(s[i]>=97))))
    		{
				count++;
				temp += s[i];
    		}
    	}
    	for(int i=0;i<count/2;i++)
    	{
    		if(temp[i] != temp[count-i-1])
    		{
    			return false;
    		}
    	}
        return true;
    }
};

int main(int argc,char ** argv)
{
	string line;
	getline(cin,line);
	Solution * mySolution = new Solution();
	cout<<mySolution->isPalindrome(line)<<endl;
	return 0;
}