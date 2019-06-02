#include <iostream>
#include <string>
#include <vector>
#include "math.h"
using namespace std;

class Solution {
public:
	string cal(unsigned int num)
	{
        string result = "";
        while(num/16 != 0)
        {
        	 result.insert(result.begin(),mylist[num%16]);
        	 num = num/16; 
        }
        result.insert(result.begin(),mylist[num%16-1]);
        return result;
	}
    string toHex(int num) {
    	string result = "";
    	if(num == 0)
    	{
    		return "0";
    	}else if(num > 0)
    	{
			result = cal(num);
    	}else
    	{
    		unsigned int subnum =  pow(2,32) + num;
			result = cal(subnum);
    	}
        return result;
    }
private:
	char mylist[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
};

int main(int argc, char ** argv)
{
	Solution * mySolution = new Solution();
	mySolution->toHex(16);
	return 0;
}