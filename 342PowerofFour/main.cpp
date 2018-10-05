#include <iostream>
using namespace std;

bool isPowerOfTwo(int num) {
    while(num != 1){
    	if(num%2 != 0){
    		return false;
    	}else{
    		num = num/2;
    	}
    }
    if(num == 1){
    	return true;
    }
    return false;
}

bool isPowerOfFour(int num) {
	if(num == 1 ){
		return true;
	}else if(num <= 3){
		return false;
	}
	int count = 0;
	while(num != 1){
    	if(num%2 != 0){
    		return false;
    	}else{
    		num = num/2;
    		count++;
    	}
	}

	if(num == 1){
    	return (count%2 == 0)?true:false;
    }
    return true;   
}


int main(int argc, char ** argv){

	cout<<isPowerOfFour(64)<<endl;
	return 0;
}