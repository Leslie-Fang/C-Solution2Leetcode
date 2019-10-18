#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
    	if (!s.length() && !t.length())
        return true;
    	int find = 0;
    	int index = 0;
        for(int i=0;i<s.size();i++)
        {
        	find = 0;
        	for(int j=index;j<t.size();j++)
        	{
        		index = j;
        		if(t[j] == s[i])
        		{
        			find = 1;
        			break;
        		}
        	}
        	index += 1;
        	if(find == 0)
        	{
        		return false;
        	}
        }
        return true;
    }
};

int main(){
	string s;
	string t;
	getline(cin,s);
	getline(cin,t);
	Solution * mySolution = new Solution();
	cout<<mySolution->isSubsequence(s,t)<<endl;
	delete mySolution;
	return 0;
}