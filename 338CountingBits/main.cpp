#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
    	int base = 0;
    	vector<int> res;
    	res.push_back(0);
    	for(int i=0;i<num;i++){
    		int temp = i;
    		while(temp%2 != 0){
    			base -= 1;
    			temp = temp/2;
    		}
    		base += 1;
    		res.push_back(base);
    	}
        for(auto r:res){
        	cout<<r<<endl;
        }
        return res;
    }
};

int main(int argc, char ** argv){
	Solution * mySolution = new Solution();
	// int a[6] = {0,1,1,2,1,2};
	// vector<int> input(a,a+6);
	mySolution->countBits(5);
	delete mySolution;
	return 0;
}