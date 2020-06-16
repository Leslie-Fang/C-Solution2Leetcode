#include <iostream>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int res = 0;
        int temp = n;
        int last = 0;
        int cur = 1;
        while(temp>=cur){
        	res += 1;
        	temp = temp - cur;
        	cur += 1;
        }

        return res;
    }
};

int main(int argc, char ** argv){
	string sinput;
	getline(cin, sinput);
	int input = stoi(sinput);
	Solution * mySolution = new Solution();
	//cout<<input<<endl;
	cout<<mySolution->arrangeCoins(input)<<endl;
	delete mySolution;

	return 0;
}