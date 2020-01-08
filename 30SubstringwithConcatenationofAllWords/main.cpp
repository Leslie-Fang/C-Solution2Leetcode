#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    	vector<int> res;
    	if(s.size() == 0 || words.size() == 0)
    	{
    		return res;
    	}
    	int l_single_word = words[0].size();
    	int ll = l_single_word*words.size();
    	for(int i=0;i<s.size()-ll+1;i++)
    	{
    		if(same_word(s, i, i+ll, words, l_single_word, ll)){
    			res.push_back(i);
    		}
    	}
    	for(vector<int>::iterator it = res.begin();it!= res.end();it++)
    	{
    		cout<<*it<<endl;
    	}
    	return res;
    }

    bool same_word(string & s_origin, int begin, int end, vector<string> words, int & l_single_word, int & ll){
    	int i = 0;
    	string s = s_origin.substr(begin,end-begin);
    	while(i<s.size()-l_single_word+1)
    	{
			string temp = s.substr(i,l_single_word);
			vector<string>::iterator it = find(words.begin(),words.end(),temp);
			if( it == words.end())
			{
				return false;
			}
			else
			{
				words.erase(it);
			}
    		i = i + l_single_word;
    	}
    	return words.size()==0;
    }
};

int main(int argc, char ** argv){
	string a[2] = {"foo","bar"};
	vector<string> inputs(a,a+2);
	Solution * mySolution = new Solution();
	mySolution->findSubstring("barfoothefoobarman", inputs);
	delete mySolution;
	return 0; 
}