#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num);
};

int main(int argc, char ** argv){
	Solution * mySolution = new Solution();
	cout<<mySolution->isPerfectSquare(atoi(argv[1]))<<endl;
	return 1;
}

bool Solution::isPerfectSquare(int num){
	long i=0,key=0;
	while(key < num){
		i++;
		key = i*i;
	}
	if(key == num) return true;
	return false;
}