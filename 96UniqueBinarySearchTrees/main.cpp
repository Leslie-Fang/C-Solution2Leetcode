#include <iostream>
using namespace std;

class Solution {
public:
    int numTrees(int n);
    int sub_numTrees(int n, int * count);
};

int main(int argc,char ** argv){
	Solution * mySolution = new Solution();
	cout<<mySolution->numTrees(3)<<endl;
	return 0;
}

int Solution::numTrees(int n){
	int * count= new int[n+1];
	memset(count,0,sizeof(int)*(n+1));
	count[0] =1;
	int res = sub_numTrees(n,count);
	delete [] count;
	return res;
}

int Solution::sub_numTrees(int n, int * count){
	if(count[n] != 0){
		return count[n];
	}
	int res=0,left=0,right=0;
	for(int i=1;i<=n;i++){
		left = sub_numTrees(i-1,count);
		count[i-1] = left;
		right  = sub_numTrees(n-i,count);
		count[n-i] = right;
		res += left * right;
	}
	return res;
}