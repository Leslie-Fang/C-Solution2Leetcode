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
    	stack<int> myStack;
    	myStack.push(-1);
    	int length = s.size();
    	int max = 0;
    	for(int i=0;i<length;i++)
    	{
    		if(s[i] == '(')
    		{
    			myStack.push(i);
    		}else
    		{
    			myStack.pop();
    			if(myStack.empty())
    			{
    				myStack.push(i);
    			}else
    			{
    				max = max<i-myStack.top()?i-myStack.top():max;
    			}
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