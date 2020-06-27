#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
    	int length1 = num1.length();
    	int length2 = num2.length();
    	bool positive = false;
    	if((num1[0] == '-' && num2[0] == '-') || (num1[0] != '-' && num2[0] != '-'))
    	{
    		positive = true;
    	}
    	if(num1[0] == '-')
    	{
    		num1 = num1.substr(1,length1-1);
    		length1 = length1 -1;
    	}
    	if(num2[0] == '-')
    	{
    		num2 = num2.substr(1,length2-1);
    		length2 = length2 -1;
    	}
    	unsigned long sum = 0;
    	for(int i=length2-1;i>=0;i--)
    	{
    		for(int j=length1-1;j>=0;j--)
    		{
    			int a = num2[i]-'0';
    			int b = num1[j]-'0';
    			unsigned long temp = a * b * pow(10,length1-1-j) * pow(10,length2-1-i);
    			cout<<temp<<endl;
    			sum += temp;
    			cout<<"sum:"<<sum<<endl;
    		}
    	}
    	//cout<<sum<<endl;
    	string res = to_string(sum);
    	if(positive == false)
    	{
    		res.insert(0,"-");
    	}
    	return res;
    }
};

int main(int argc, char ** argv){
	Solution * mySolution = new Solution();
	//cout<<mySolution->divide(-2147483648, -1)<<endl;
	cout<<mySolution->multiply("498828660196", "840477629533")<<endl;
	delete mySolution;
	return 0;
}