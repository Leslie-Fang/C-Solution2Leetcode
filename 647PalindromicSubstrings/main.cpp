#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
	struct centor
	{
		int start;
		int end;
		centor(int a, int b) : start(a), end(b) {}
	};
    int countSubstrings(string s) {
    	//https://leetcode-cn.com/problems/palindromic-substrings/solution/hui-wen-zi-chuan-by-leetcode/
    	//有2N-1 个可能的中心， 以此为基础向两边延伸
    	queue<centor> q;
    	int res = s.length();
    	for(int i=0;i<s.length();i++)
    	{
    		q.push(centor(i,i));
    	}
    	for(int i=0;i<s.length()-1;i++)
    	{
    		if(s[i] == s[i+1])
    		{
    			q.push(centor(i,i+1));
    			res += 1;
    		}
    	}
    	while(1)
    	{
    		int len = q.size();
    		for(int i=0;i<len;i++)
    		{
                centor tem = q.front();
                q.pop();
                if(tem.start == 0 || tem.end == s.length()-1)
                {
                	continue;
                }else
                {
                	if(s[tem.start-1] == s[tem.end+1])
                	{
                		res += 1;
                		q.push(centor(tem.start-1,tem.end+1));
                	}
                }

    		}
    		if(q.empty())
    		{
    			break;
    		}
    	}
    	return res; 
    }
};


int main(int argc, char ** argv)
{
	string input;
	getline(cin, input);
	Solution * mySolution = new Solution();
    cout<<mySolution->countSubstrings(input)<<endl;
	delete mySolution;
	//cout<<input<<endl;
	return 0;
}