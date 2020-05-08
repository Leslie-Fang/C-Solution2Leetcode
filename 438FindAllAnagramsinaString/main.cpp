#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	bool isAnagrams(string s, int start, string p){
		int length = p.length();
		if(start + length > s.length())
		{
			return false;
		}
		//string temp = s.substr(start, length);
		int a[26] = {0};
		for(int i=0;i<length;i++)
		{
			a[s[i+start]-int('a')] += 1;
			a[p[i]-int('a')] -= 1;
		}
		for(int i=0;i<26;i++)
		{
			if(a[i] != 0)
			{
				return false;
			}
		}
		return true;
	} 
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.length() <= p.length()) {
        	return res;
        }
        for(int i=0;i<=s.length() - p.length();i++)
        {
        	if(isAnagrams(s,i,p))
        	{
        		res.push_back(i);
        	}
        }
        return res;
    }
};

int main(int argc, char ** argv) {
	string input1;
	string input2;
	getline(cin, input1);
	getline(cin, input2);
	Solution * mySolution = new Solution();
	vector<int> res = mySolution->findAnagrams(input1, input2);
	for(auto item : res) {
		cout<<item<<endl;
	}
	return 0;
}