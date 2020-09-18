#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

	void DFS(const vector<int>& A, int index, int compare_index, int & res, const long& difference){
		if((A[index] - long(A[compare_index])) == difference){
			res += 1;
			for(int m=index+1;m<A.size();m++){
	        	DFS(A, m, index, res, difference);
	        }
		}
		return;
	}

    int numberOfArithmeticSlices(vector<int>& A) {
    	if(A.size() < 3){
    		return 0;
    	}
        int res = 0;
        long difference = 0;
        int compare;

        for(int i=0;i<A.size()-2;i++){
        	for(int j=i+1; j<A.size()-1; j++){
        		difference = A[j] - long(A[i]);
	        	for(int k=j+1; k<A.size(); k++){
	        		if(A[k] - long(A[j]) == difference){
	        			res += 1;
	        			for(int m=k+1;m<A.size();m++){
	        				DFS(A, m, k, res, difference);
	        			}
	        		}
	        	}
        	}
        }
        return res;
    }
};

int main(int argc, char ** argv){
	Solution * mySolution = new Solution();
	int a[4] = {2, 2, 3, 4};
	//int a[5] = {2, 4, 6, 8, 10};
	vector<int> vinput(a, a+4);
	cout<<mySolution->numberOfArithmeticSlices(vinput)<<endl;
	return 0;
}