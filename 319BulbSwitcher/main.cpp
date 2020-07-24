#include<iostream>

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        int res = 1;
        while (res * res <= n) ++res;
        return res - 1;
    }
};

int main(int argc, char ** argv){
	Solution * mySolution = new Solution();
	string sinput;
	getline(cin, sinput);
	cout<<mySolution->bulbSwitch(stoi(sinput))<<endl;
	delete mySolution;
	return 0;
}