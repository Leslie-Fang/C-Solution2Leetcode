#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
    	if(dividend == 0)
    	{
    		return 0;
    	}
    	bool positive = false;
    	if((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
    	{
    		positive = true;
    	}
    	long dividend2 = dividend;
    	long divisor2 = divisor;
    	if(dividend2 < 0)
    	{
    		dividend2 = abs(dividend2);
    	}
    	if(divisor2 < 0)
    	{
    		divisor2 = abs(divisor2);
    	}
    	unsigned long count = 1;
    	unsigned long count_down = 1;
    	unsigned long count_up = 1;
    	while(divisor2 * count_up <= dividend2)
    	{
    		count_down = count_up;
    		count_up *= 2;
    	}
    	count = count_down;
    	while(divisor2 * count <= dividend2)
    	{
    		count += 1;
    	}
    	long res = positive?(count-1):-(count-1);
    	if(res >=  2147483648)
    	{
    		return 2147483647;
    	}else{
    		return res;
    	} 
    }
};

int main(int argc, char ** argv){
	Solution * mySolution = new Solution();
	//cout<<mySolution->divide(-2147483648, -1)<<endl;
	cout<<mySolution->divide(10, 3)<<endl;
	delete mySolution;
	return 0;
}