#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x);
};

int main(int argc, char** argv){
	cout<<"Hello"<<endl;
	int input=15;
	Solution * mySolution = new Solution();
	cout<<mySolution->isPalindrome(input)<<endl;
	return 1;
}

bool Solution::isPalindrome(int x){
	if(x<0){
		return false;
	}else if(x==0){
		return true;
	}
	// string sinput = to_string(x);
	// int length = sinput.length();
	// int left=length-1;
	// int right=0;
	// while(1){
	// 	if(left <= right){
	// 		return true;
	// 	}else{
	// 		if(sinput[left] != sinput[right]){
	// 			return false;
	// 		}else{
	// 			left --;
	// 			right ++;
	// 		}
	// 	}
	// }
	// return true;
	int length=1;
	int input=x;
	vector<int> leftInput;
	while(input/10 != 0){
		length++;
		leftInput.push_back(input%10);
		input = input/10;
	}
	leftInput.push_back(input%10);
	for(int i=0;i<length/2;i++){
		if(leftInput[i] != leftInput[length-i-1]){
			return false;
		}
	}
	return true;
}