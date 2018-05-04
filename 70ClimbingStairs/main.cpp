#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n);
};
int subClimbStairs(int n);
int main(int argc,char ** argv){
	cout<<"hello world!"<<endl;
	Solution * mySolution = new Solution();
	cout<<mySolution->climbStairs(atoi(argv[1]))<<endl;
	delete mySolution;
	return 1;
}

int Solution::climbStairs(int n){
	int * data = new int[n];
	data[0] = 1;
	data[1] = 2;
	for(int i=2;i<n;i++){
		data[i] = data[i-1]+data[i-2];
	}
	return data[n-1];
}

// int subClimbStairs(int n){
// 	// if(n==1){
// 	// 	count +=1;
// 	// 	return;
// 	// }else if(n==2){
// 	// 	count +=2;
// 	// 	return;
// 	// }else{
// 	// 	subClimbStairs(n-1,count);
// 	// 	subClimbStairs(n-2,count);
// 	// }
// 	if(n==1){
// 		return 1;
// 	}else if(n==2){
// 		return 2;
// 	}else{
// 		return subClimbStairs(n-2)+subClimbStairs(n-1);
// 	}
// }