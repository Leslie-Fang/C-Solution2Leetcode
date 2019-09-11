#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	map<char, string> look;
	Solution()
	{
		look.insert(pair<char,string>('2',"abc"));
		look.insert(pair<char,string>('3',"def"));
		look.insert(pair<char,string>('4',"ghi"));
		look.insert(pair<char,string>('5',"jkl"));
		look.insert(pair<char,string>('6',"mno"));
		look.insert(pair<char,string>('7',"pqrs"));
		look.insert(pair<char,string>('8',"tuv"));
		look.insert(pair<char,string>('9',"wxyz"));
	}
	void DFS(string digits, string sub, char add, vector<string> &res)
	{
		sub += add;
    	if(digits.length() == 0)
    	{
    		res.push_back(sub);
    		return;
    	}
    	for(int i=0;i<look[digits[0]].length();i++)
    	{
    		DFS(digits.substr(1, digits.length()-1), sub, look[digits[0]][i], res);
    	}
    	return;
	}

    vector<string> letterCombinations(string digits) {
    	vector<string> res;
    	if(digits.length() == 0)
    	{
    		return res;
    	}
    	string sub = "";
    	for(int i=0;i<look[digits[0]].length();i++)
    	{
    		DFS(digits.substr(1, digits.length()-1), sub, look[digits[0]][i], res);
    		//cout<<look[digits[0]][i]<<endl;
    	}
    	return res;
    }
};

int main(int argc, char ** argv)
{
	string input;
	getline(cin,input);
	Solution * mySolution = new Solution();
	vector<string> res = mySolution->letterCombinations(input);
	for(vector<string>::iterator it=res.begin();it!=res.end();it++)
	{
		cout<<*it<<endl;
	}
	delete mySolution;
	return 0;
}