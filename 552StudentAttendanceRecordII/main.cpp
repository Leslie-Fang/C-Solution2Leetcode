#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	void BPS(int n, int & res, int a_num, int c_L) {
		if(n == 0)
		{
			res += 1;
			return;
		}else{
			if(a_num < 1)
			{
				//Choose A
				BPS(n-1, res, a_num+1, 0);
			}
			if(c_L < 2){
				//Choose L;
				BPS(n-1, res, a_num, c_L+1);
			}
			//Choose P
			BPS(n-1, res, a_num, 0);
		}
		return;
    }

    int checkRecord(int n) {
    	int res = 0;
    	BPS(n, res, 0, 0);
    	return res;
    }
};

int main(int argc, char ** argv){
    string input;
    getline(cin, input);
    Solution * mySolution = new Solution();
    cout<<mySolution->checkRecord(stoi(input))<<endl;
    delete mySolution;
}