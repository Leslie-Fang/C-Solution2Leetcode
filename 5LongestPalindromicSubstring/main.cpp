#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s);
};
bool isPalindrome(string s);

int main(){
	Solution mySolution;
	string input="";
	// cout<<isPalindrome(input)<<endl;
	cout<<mySolution.longestPalindrome(input)<<endl;
	return 1;
}

string Solution::longestPalindrome(string s){
	int l=s.length();
	int count=l;
	string subS;
	while(count != 0){
		for(int i=0;i<=(l-count);i++){
			subS=s.substr(i,count);
			if(isPalindrome(subS)){
				return subS;
			}
		}
		count--;
	}
	return "";
}

bool isPalindrome(string s){
	int i=0;
	int j=s.length()-1;
	while(i < j){
		if(s[i] != s[j]){
			return false;
		}
		i++;
		j--;
	}
	return true;
}


