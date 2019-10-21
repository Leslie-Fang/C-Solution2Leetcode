#include <iostream>
#include <math.h>
using namespace std;


class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int temp;
    	if(n>10)
    	{
    		return 0;
    	}else if(n==0)
    	{
    		return 1;
    	}
    	else if(n==1)
    	{
    		return 10;
    	}else if(n==2)
    	{
    		temp = 81;
    	}else
    	{
    		temp = countNumbersWithUniqueDigits(n-1)*(10-n+1);
    	}
        return temp + countNumbersWithUniqueDigits(n-1);
    
    }
};

int main()
{
	string input;
	getline(cin,input);
	Solution * mySolution = new Solution();
	cout<<mySolution->countNumbersWithUniqueDigits(stoi(input))<<endl;
	delete mySolution;
}