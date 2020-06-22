#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    	int res = 0;
    	int index = 0;

    	while(index < flowerbed.size())
    	{
    		if(flowerbed[index] == 0)
    		{
    			if(index+1<flowerbed.size() && index-1>=0)
    			{
    				if(flowerbed[index+1] == 0 && flowerbed[index-1] == 0)
    				{
    					res+=1;
    					flowerbed[index] = 1;
    					index += 2;
    				}else if(flowerbed[index+1] == 0)
    				{
    					index += 1;
    				}else
    				{
    					index += 2;
    				}
    			}else if(index+1<flowerbed.size())
    			{
    				if(flowerbed[index+1] == 0)
    				{
    					res+=1;
    					flowerbed[index] = 1;
    				}
    				index += 2;
    			}
    			else if(index-1>=0)
    			{
    				if(flowerbed[index-1] == 0)
    				{
    					res +=1;
    				}
    				index += 1;
    			}else
    			{
    				res += 1;
    				index += 2;
    			}
    		}else
    		{
    			index += 1;
    		}
    		if(res >= n)
    		{
    			return true;
    		}
    	}
    	if(res >= n)
    	{
    		return true;
    	}
    	return false;
    }
};

int main(int argc, char ** argv)
{
	int a[6] = {1,0,0,0,0,1};
	vector<int> input(a,a+6);
	Solution * mySolution = new Solution();
	cout<<mySolution->canPlaceFlowers(input, 2)<<endl;
	delete mySolution;
	return 0;
}