#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    bool isHappy(int n);
    int calHappy(int n);
};
int main(int argc,char ** argv){
	Solution * mySolution = new Solution();
	cout<<mySolution->isHappy(19)<<endl;
	return 1;
}

bool Solution::isHappy(int n){
	if(n!=1){
		// vector<int> appears;
		// appears.push_back(n);
		// while(1){
		// 	n=calHappy(n);
		// 	if(n==1){
		// 		return true;
		// 	}
		// 	if(find(appears.begin(),appears.end(),n)!=appears.end()){
		// 		return false;
		// 	}else{
		// 		appears.push_back(n);
		// 	}
		// }
		map<int,int> appears;
		appears[n]=1;
		while(1){
			n=calHappy(n);
			if(n==1){
				return true;
			}
			if(appears.find(n) != appears.end()){
				return false;
			}else{
				appears[n]=1;
			}
		}
		
	}
	return true;
}

int Solution::calHappy(int n){
	int res=0;
	while(n/10 != 0){
		res += (n%10)*(n%10);
		n = n/10;
	}
	res += (n)*(n);
	return res;
}