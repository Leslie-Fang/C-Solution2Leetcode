#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s);
};

int main(int argc,char** argv){
	Solution * mySolution = new Solution();
	cout<<mySolution->longestPalindrome("abccccdd")<<endl;
	return 0;
}
int Solution::longestPalindrome(string s){
	//cout<<"helo"<<endl;
	int map[256] = {0};
	for(int i=0;i<s.length();i++){
		map[s[i]]++;
	}
	int length=0;
	bool single = false;
	for(int i=0;i<256;i++){
		if(map[i]>0){
			length += 2*(map[i]/2);
			if(map[i]%2!=0){
				single = true;
			}
		}
	}
	if(single){
		length++;
	}
	return length;
}