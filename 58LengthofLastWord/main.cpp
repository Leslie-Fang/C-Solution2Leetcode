#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s);
};

int main(int argc, char ** argv){
	string input ="";
	for(int i=1;i<argc;i++){
		for(int j=0;argv[i][j] != '\0';j++){
			cout<<argv[i][j]<<endl;
			input +=argv[i][j];
		}
		if(i != argc-1){
			input +=" ";
		}
	}
	cout<<input<<endl;
	Solution * mySolution = new Solution();
	cout<<mySolution->lengthOfLastWord(input)<<endl;
	return 1;

}

int Solution::lengthOfLastWord(string s){
	if(s == ""){
		return 0;
	}
	int cNumber=0;
	int length=s.length();
	int point=0;
	while(s[point] == ' '){
		point ++;
		if(point == length){
			return 0;
		}
	}
	while(1){
		cNumber =0;
		while(s[point] != ' '){
			cNumber ++;
			point ++;
			if(point == length){
				return cNumber;
			}
		}
		while(s[point] == ' '){
			point ++;
			if(point == length){
				return cNumber;
			}
		}
	}
	return cNumber;
}