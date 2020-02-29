#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
	int maxLength(string &s, int start, int end)
	{
		stack<char> myStack;
		char temp;
		for(int i=start;i<=end;i++)
		{
			if(s[i] == '(')
			{
				myStack.push(s[i]);
			}else
			{
				if(myStack.empty())
				{
					return 0;
				}else
				{
					temp = myStack.top();
					if(temp == ')')
					{
						return 0;
					}else
					{
						myStack.pop();
					}
				}
			}
		}
		return myStack.empty()?end-start+1:0;
	}
    int longestValidParentheses(string s) {
    	int max = 0;
    	int index = 0;
    	int temp = 0;
    	stack<char> myStack;
    	int length = s.size();
    	int init = length%2==0?length:length-1;
    	cout<<init<<endl;
    	if(length <= 1)
    	{
    		return 0;
    	}
        for(int size=init;size<=length;size -=2)
        {
        	if(size <= 0)
        	{
        		break;
        	}
        	index = 0;
        	while(index+size <= length)
        	{
        		temp = maxLength(s, index, index+size-1);
        		if(temp != 0)
        		{
        			return temp;
        		}
        		index += 1;
        	}
        }
        return max;
    }
};

int main(int argc, char ** argv)
{
	string input;
	getline(cin, input);
	Solution * mySolution = new Solution();
	//cout<<mySolution->maxLength(input,0,input.size()-1)<<endl;
	cout<<mySolution->longestValidParentheses(input)<<endl;
	delete mySolution;
	return 0;
}