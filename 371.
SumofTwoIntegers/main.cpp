#include <iostream>

using namespace std;

class Solution
{
public:
    int getSum(int a, int b);
};

int main()
{
	Solution * mySolution = new Solution();
	cout<<mySolution->getSum(1,2)<<endl;
	return 0;

}
int Solution::getSum(int a, int b)
{

	 int sum = 0, carry = 0;
     for (unsigned mask = 1; mask != 0; mask <<= 1) {
          sum |= (a^b^carry)&mask;
          carry = ((a&b) | ((a^b)&carry)) << 1;
     }
     return sum;
}