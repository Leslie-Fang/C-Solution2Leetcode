#include <iostream>
using namespace std;
class Solution {
public:
    bool isUgly(int num) {
    	if(num <= 0)
    	{
    		return false;
    	}
    	int cnum = num;
    	while(cnum%2 == 0)
    	{
    		cnum = cnum / 2;
    	}
    	while(cnum%3 == 0)
    	{
    		cnum = cnum / 3;
    	}
    	while(cnum%5 == 0)
    	{
    		cnum = cnum / 5;
    	}
    	if(cnum == 1)
    	{
    		return true;
    	}
        return false;
    }
};

int main()
{
	Solution * mySolution = new Solution();
	cout<<mySolution->isUgly(14)<<endl;
	return 0;
}