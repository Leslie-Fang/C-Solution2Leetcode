#include <iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int comp = x ^ y;
        int res = 0;
        while(comp > 0){
            res += comp & 1;
            comp >>= 1;
        }
        return res;
    }
};

int main(int argc, char ** argv){
	Solution * mySolution = new Solution();
	cout<<mySolution->hammingDistance(1,4)<<endl;
	delete mySolution;
	return 0;
}