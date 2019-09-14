#include<iostream>
#include<map>
#include<stack>
#include<string>

using namespace std;
class Solution {
public:
    bool isValid(string s) {
       map<char, char> mapping;
       stack<char> container; 
       mapping.insert(pair<char,char>('(',')'));
       mapping.insert(pair<char,char>('[',']'));
       mapping.insert(pair<char,char>('{','}'));
       int len = s.length();
       if(len == 0)
       {
       	 return true;
       }
       for(int i=0;i<len;i++)
       {
       	if(s[i] == '(' || s[i] == '[' || s[i] == '{')
       	{
       		container.push(s[i]);
       	}else
       	{
       		if(container.size() == 0)
       		{
       			return false;
       		}
       		if(mapping[container.top()] == s[i])
       		{
       			container.pop();
       		}else
       		{
       			return false;
       		}
       	}
       }
       return container.size() == 0?true:false; 
    }
};

int main(int argc, char ** argv)
{
	string input;
	getline(cin,input);
	Solution * mySolution = new Solution();
	cout<<mySolution->isValid(input)<<endl;
	delete mySolution;

	return 0;
}