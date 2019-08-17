#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        std::vector<int> res(num_people);
        int temp = 1;
        int index = 0;
        while(candies > 0)
        {
        	if(temp%num_people == 0)
        	{
        		index = num_people - 1;
        	}
        	else
        	{
        		index = temp%num_people-1;
        	}
        	if(candies >= temp)
        	{
        		res[index] += temp;
        		candies = candies - temp;
        	}else{
        		res[index] += candies;
        		candies = 0;
        	}
        	temp += 1;
        }
        return res;
    }
};

int main(int argc, char ** argv)
{

	return 1;
}