#include <iostream>
using namespace std;
class Solution {
public:
    int trailingZeroes(int n) {
    	int res = 0;
    	//10是2*5,将n的阶层因式分解之后，计算2的个数和5的个数
    	//因为2的个数一定比5的个数多，所以只需要计算5的个数就可以了
    	while(n){
    		res += n/5;
    		n/=5;
    	}
    	return res;
    }
};

int main(int argc, char ** argv){
	Solution * mySolution = new Solution();
	string input;
	getline(cin, input);
	cout<<mySolution->trailingZeroes(stoi(input))<<endl;
	return 0;
}