#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int guessNumber(int n);
    int guess(int num);
    Solution(int base):base(base){};
private:
	int base;
};

int main(int argc, char ** argv){

	string input;
	getline(cin, input);
	string base;
	getline(cin, base);
	Solution * mySolution = new Solution(stoi(base));
	cout<<mySolution->guessNumber(stoi(input))<<endl;
	delete mySolution;

	return 1;

}

int Solution::guessNumber(int n){
	bool bingo=false;
	long left = 1;
	long right = n;
	long gu;
	//int base=n;
	while(1){
		gu = (left+right)/2;
		//cout<<"Gu is: "<<gu<<endl;
		switch (guess(gu)){
			case -1:{
				//n = n-n/2;
				right = gu -1;
				break;
			}
			case 1:{
				left = gu + 1;
				break;
			}
			default:{
				bingo=true;
			    break;
			}
		}
		if(bingo){
			break;
		}
	}
	return gu;
}

int Solution::guess(long num){
	if(num < base){
		return 1;
	}else if(num > base){
		return -1;
	}
	return 0;
}