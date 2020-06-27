#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        vector<int> dp(A.size()+1, 0);
        for(int i=1;i<=A.size();i++) {
            int m=0;
            for(int j=i-1;j>=0&&j>=i-K;j--) {
                m=max(m, A[j]);
                dp[i]=max(dp[i], dp[j]+m*(i-j));
            }
        }
        return dp.back();
    }
};

int main(int argc, char ** argv){
	int input[7] = {1,15,7,9,2,5,10};
	vector<int> inputs(input,input+7);
	Solution * mySolution = new Solution();
	cout<<mySolution->maxSumAfterPartitioning(inputs, 3)<<endl;
	delete mySolution;
	return 0;
}