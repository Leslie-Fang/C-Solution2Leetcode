#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S);
};

int main(int argc,char** argv){
	Solution * mySolution = new Solution();
	cout<<mySolution->numJewelsInStones("aA","ZZZ")<<endl;
	return 0;
}
int Solution::numJewelsInStones(string J, string S){
	int map[256]={0};
	for(int i=0;i<J.length();i++){
		map[J[i]] =1;
	}
	int count=0;
	for(int i=0;i<S.length();i++){
		if(map[S[i]] != 0){
			count++;
		}
	}
	return count;
}