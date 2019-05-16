#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class Solution {
public:
	int cal(int base)
	{
		int res=0;
		while(base > 0)
		{
			res += base * (pow(10,base)-pow(10,base-1));
			base -= 1;
		}
		return res;
	}
    int findNthDigit(int n)
    {
    	int base = 1;
    	while(true)
    	{
    		int exceed = 0;
    		if(cal(base) < 0)
    		{
    			exceed = 1;
    		}
    		if(n <= cal(base) or exceed)
    		{
    			int base_start_n = pow(10,base-1);
    			int base_start_d = cal(base-1);
    			int left = (n-base_start_d)/base;
    			int left_d = (n-base_start_d)%base;
    			int num = base_start_n + left - 1;
    			if(left_d == 0)
    			{
    				return num%10;
    			}else
    			{
    				num = num + 1;
    				vector<int> temp;
    				while(num/10 != 0)
    				{
						temp.push_back(num%10);
    					num = num / 10;
    				}
    				temp.push_back(num);
    				return *(temp.end()-left_d);
    			}
    		}else
    		{
    			base += 1; 
    		}
    	}
        return n;
    }
};
int main()
{
	Solution * mySolution = new Solution();
	cout<<mySolution->findNthDigit(1000000000)<<endl;
}