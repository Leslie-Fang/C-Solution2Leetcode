//
// Created by leslie-fang on 2017/6/11.
//
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
    int reverse(int x);
};


int main(){
	Solution *mySolution = new Solution();
	cout<<pow(2, 31)-1<<endl;
    cout<<mySolution->reverse(10987890)<<endl;
    return 0;
}

int Solution::reverse(int x){
	int upper = 2147483647;
	int lower = -2147483648;
    long res=0;
    bool negative=false;
    if(x<0){
		negative=true;
		x = -x;
    }
    while(1){
    	res = res*10+x%10;
    	x = x/10;
    	if(x==0){
    		break;
    	}
    }
    if(negative){
    	res =-res;
    }
    if(res < lower || res>upper){
    	return 0;
    }
	return res;
}
