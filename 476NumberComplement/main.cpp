#include <iostream>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int tmp = 1;
        //find the tmp with all 1 in binary and has the same length of bits as num
        while (tmp < num)
        {
            tmp <<= 1;
            tmp += 1;
        }
        //XOR between tmp and num
        return (tmp^num);
    }
};


int main(int argc, char ** argv){
	Solution * mySolution = new Solution();
	string sinput;
	getline(cin, sinput);
	cout<<mySolution->findComplement(stoi(sinput))<<endl;
	delete mySolution;
	return 0;

}