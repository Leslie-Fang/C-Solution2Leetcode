#include <iostream>
using namespace std;
class Solution {
public:
    int titleToNumber(string s);
};
int main(int argc,char ** argv){
	Solution * mySolution = new Solution();
	cout<<mySolution->titleToNumber("AB")<<endl;
	return 1;
}

int Solution::titleToNumber(string s){
	int res=0;
	for(int i=0;i<s.length();i++){
		res = res*26+(int)(s[i]-'A'+1);
	}
	return res;
}