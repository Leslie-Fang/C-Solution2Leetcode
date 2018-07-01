#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs);
};

int main(int argc,char** argv){
	vector<string> input;
	// input.push_back("dog");
	// input.push_back("racecar");
	// input.push_back("car");
	input.push_back("flower");
	input.push_back("flow");
	input.push_back("flight");
	Solution * mySolution = new Solution();
	cout<<mySolution->longestCommonPrefix(input)<<endl;
	return 0;
}
string Solution::longestCommonPrefix(vector<string>& strs){
	int myLength=strs[0].length();
	vector<string>::iterator least;
	for(vector<string>::iterator it=strs.begin();it != strs.end();it++){
		if((*it).length()<myLength){
			myLength=(*it).length();
			least = it;
		}
	}
	int res=myLength;
	for(vector<string>::iterator it=strs.begin();it != strs.end();it++){
		int subL=0;
		for(int i=0;i<(*it).length();i++){
			if((*least)[i] == (*it)[i]){
				subL++;
			}
		}
		if(subL<res){
			res = subL;
		}
	}
	string sres="";
	if(res==0){
		return "";
	}
	for(int i=0;i<res;i++){
		sres += (*least)[i];
	}
	return sres;
}