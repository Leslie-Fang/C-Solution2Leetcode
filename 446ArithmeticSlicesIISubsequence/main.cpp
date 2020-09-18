#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	// bool isArithmeticSlices(const vector<int>& A, int start, int end){
	// 	if(end-start < 2){
	// 		return false;
	// 	}
	// 	int difference = A[start+1] - A[start];
	// 	for(int i=start+2;i<=end;i++){
	// 		if((A[i] - A[i-1]) != difference){
	// 			return false;
	// 		}
	// 	}
	// 	return true;
	// }

    int numberOfArithmeticSlices(vector<int>& A) {
    	if(A.size() < 3){
    		return 0;
    	}
        int res = 0;
        int difference = 0;
        for(int i=0;i<A.size()-2;i++){
        	for(int step=1; i+step*2 < A.size(); step++){
	        	difference = A[i+step] - A[i];
	        	if(A[i+step*2] - A[i+step] != difference){
	        		continue;
	        	}
	        	res += 1;
	        	for(int j=i+3*step;j<A.size();j = j+step){
	        		if(A[j] - A[j-step] == difference){
	        			res += 1;
	        		}else{
	        			break;
	        		}
	        	}
        	}
        }
        return res;
    }
};

int main(int argc, char ** argv){
	Solution * mySolution = new Solution();
	//int a[3] = {3, 2, 1};
	int a[5] = {2, 4, 6, 8, 10};
	vector<int> vinput(a, a+5);
	cout<<mySolution->numberOfArithmeticSlices(vinput)<<endl;
	return 0;
}