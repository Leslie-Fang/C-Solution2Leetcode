#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool isArithmeticSlices(const vector<int>& A, int start, int end){
		if(end-start < 2){
			return false;
		}
		int difference = A[start+1] - A[start];
		for(int i=start+2;i<=end;i++){
			if((A[i] - A[i-1]) != difference){
				return false;
			}
		}
		return true;
	}

    int numberOfArithmeticSlices(vector<int>& A) {
    	if(A.size() < 3){
    		return 0;
    	}
        int res = 0;
        for(int i=0;i<A.size()-2;i++){
        	for(int j=i+2;j<A.size();j++){
        		if(isArithmeticSlices(A, i, j)){
        			res += 1;
        		}else{
        			break;
        		}
        	}
        }
        return res;
    }
};

int main(int argc, char ** argv){
	Solution * mySolution = new Solution();
	//int a[3] = {3, 2, 1};
	int a[4] = {1, 2, 3, 4};
	vector<int> vinput(a, a+4);
	cout<<mySolution->numberOfArithmeticSlices(vinput)<<endl;
	return 0;
}