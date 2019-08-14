#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Solution {
public:
	int a_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int b_days[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	int dayOfYear(string date) {
    	int year = 0;
    	int month = 0;
    	int day = 0;
    	int res = 0;
    	for(int i=0;i<4;i++)
    	{
    		year += ((int)date[i]-48)*pow(10,3-i);
    	}
    	for(int i=5;i<7;i++)
    	{
    		month += ((int)date[i]-48)*pow(10,6-i);
    	}
    	for(int i=8;i<10;i++)
    	{
    		day += ((int)date[i]-48)*pow(10,9-i);
    	}
    	if(year%400 == 0 ){
    		for(int i=0;i<month-1;i++)
    		{
				res += b_days[i];
    		}
    		res += day;

    	}else if(year%4 ==0 && year %100 != 0){
    		for(int i=0;i<month-1;i++)
    		{
				res += b_days[i];
    		}
    		res += day;
    	}else{
    		for(int i=0;i<month-1;i++)
    		{
				res += a_days[i];
    		}
    		res += day;
    	}
        return res;
    }
};

int main(int argc, char ** argv)
{
	Solution * mySolution = new Solution();
	string input;
	getline(cin, input);
	cout<< mySolution->dayOfYear(input)<<endl;
	return 0;
}