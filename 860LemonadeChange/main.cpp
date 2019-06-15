#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
    	map<int,int> charge;
    	charge.insert(pair<int,int>(5,0));
    	charge.insert(pair<int,int>(10,0));
    	charge.insert(pair<int,int>(20,0));
    	for(vector<int>::iterator it=bills.begin(); it != bills.end(); it++)
    	{
    		if(*it == 5)
    		{
    			charge[5] += 1;
    		}else if(*it == 10)
    		{
    			if(charge[5] > 0)
    			{
    				charge[5] -= 1;
    			}else{
    				return false;
    			}
    			charge[10] += 1;
    		}else
    		{
    			int temp = *it;
    			// while(temp > 0)
    			// {
    				// cout<<"hhh"<<endl;
    				if(charge[10] > 0)
    				{
    					temp -= 10;
    					charge[10] -= 1;
    				}
    				while(temp >= 10 && charge[5] > 0)
    				{
    					temp -= 5;
    					charge[5] -= 1;
    				}
    				if(temp > 5)
    				{
    					return false;
    				}
    			//}
    		}
    	}
       return true; 
    }
};

int main(int argc, char ** argv)
{
	Solution * mySolution = new Solution();
	int a[2] = {10,10};
	vector<int> input(a,a+2);
	cout<<mySolution->lemonadeChange(input)<<endl;
	return 0;

}