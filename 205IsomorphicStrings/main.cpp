#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t);
};

int main(int argc,char** argv){
	Solution * mySolution = new Solution();
	cout<<mySolution->isIsomorphic("aba","baa")<<endl;
	return 0;
}

bool Solution::isIsomorphic(string s, string t){
	cout<<s.length()<<endl;
	int is[256]={0};
	int it[256]={0};
	for(int i=0;i<s.length();i++){

		if(is[s[i]] == it[t[i]]){
			is[s[i]] = i+1;
			it[t[i]] = i+1;
		}else{
			return false;
		}
	}
	return true;
}