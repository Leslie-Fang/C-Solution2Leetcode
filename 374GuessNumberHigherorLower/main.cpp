#include <iostream>
using namespace std;

class Solution {
public:
    int guessNumber(int n);
};
int guess(int num);

int main(int argc, char ** argv){

	return 1;

}

int Solution::guessNumber(int n){
	bool bingo=false;
	//int base=n;
	while(1){
		switch (guess(n)){
			case -1:{
				n = n-n/2;
				break;
			}
			case 1:{
				n = n+n/2;
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
	return n;
}

int guess(int num){
	return 1;
}