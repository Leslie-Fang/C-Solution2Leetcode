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
	cout<<mySolution.longestPalindrome("babad")<<endl;
}

string Solution::longestPalindrome(string s){
	if(s.length() == 1){
		return s;
	}
	string maxS=""+s[0];
	int max=1;
	int cmax=0;
	int l =s.length();
	int flag=1;
	for (int i = 0; i < l; ++i){
		cmax = 0;
		flag=1;
		for(int j=0;i-j>=0&&i+j<l;j++){
			if(s[i-j] != s[i+j]){
				if(cmax > max){
					max = cmax;
					maxS = s.substr(i-j+1,2*(j-1)+1);
				}
				flag=0;
				break;
			}
			cmax = 2*j+1;
		}
		if(flag != 0){
			cmax = 2*i-1;
			max = cmax;
			maxS = s;
		}
		cmax = 0;
		flag =1;
		for(int j=0;i-j>=0&&i+j<l;j++){
			if(s[i-j] != s[i+j+1]){
				if(cmax > max){
					max = cmax;
					maxS = s.substr(i-j+1,2*(j-1)+2);
				}
				flag=0;
				break;
			}
			cmax = 2*j+2;
		}
		if(flag != 0){
			cmax = 2*i;
			max = cmax;
			maxS = s;
		}
	}
	return maxS;
}
