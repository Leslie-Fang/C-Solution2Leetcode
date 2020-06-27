#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
	bool isPrimes(int n){
		for(int i=2;i<=sqrt(n);i++){
			if(n%i == 0){
				return false;
			}
		}
		return true;
	}
    int countPrimes(int n) {
        int res = 0;
        if(n<=1){
        	return 0;
        }
        if(n>2){
        	res += 1;
        }
        if(n>3){
        	res += 1;
        }
        for(int i=2;i<n;i++){
        	if(i%2 != 0 && i%3 != 0 && isPrimes(i)){
        		res+=1;
        	}
        }
        return res;
    }
};

int main(int argc, char ** argv){
	Solution * mySolution = new Solution();
	string sinput;
	getline(cin, sinput);
	cout<<mySolution->countPrimes(stoi(sinput))<<endl;
	delete mySolution;
	return 0;
}