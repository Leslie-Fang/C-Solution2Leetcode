#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int fib(int N) {
    	switch(N){
    		case 0:
    			return 0;
    		case 1:
    			return 1;
    		default:
    			return fib(N-1)+fib(N-2);
    	}
    }
};

int main(int argc, char ** argv){
	string input;
	getline(cin, input);
	Solution * mySolution = new Solution();
	cout<<mySolution->fib(stoi(input))<<endl;
	delete mySolution;
}