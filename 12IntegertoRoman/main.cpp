#include <iostream>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
	// int it[7] = {1,5,10,50,100,500,1000};
	// char its[7] = {}
	map<int, char> mylist = {{1,'I'},{5,'V'},{10,'X'},{50,'L'},{100,'C'},{500,'D'},{1000,'M'}};
    string intToRoman(int num) {
    	cout<<num<<endl;
    	string res = "";
    	while(num>=1000)
    	{
    		res += 'M';
    		num = num - 1000;
    	}
    	if(num>=900)
    	{
    		res += "CM";
    		num = num - 900;
    	}
    	if(num>=500)
    	{
    		res += 'D';
    		num = num - 500;
    	}
    	if(num>=400)
    	{
    		res += "CD";
    		num = num - 400;
    	}
    	while(num>=100)
    	{
    		res += 'C';
    		num = num - 100;
    	}
    	if(num>=90)
    	{
    		res += "XC";
    		num = num - 90;
    	}
    	if(num>=50)
    	{
    		res += 'L';
    		num = num - 50;
    	}
    	if(num>=40)
    	{
    		res += "XL";
    		num = num - 40;
    	}
    	while(num>=10)
    	{
    		res += 'X';
    		num = num - 10;
    	}
    	if(num>=9)
    	{
    		res += "IX";
    		num = num - 9;
    	}

    	if(num>=5)
    	{
    		res += 'V';
    		num = num - 5;
    	}
    	if(num>=4)
    	{
    		res += "IV";
    		num = num - 4;
    	}
    	while(num>=1)
    	{
    		res += 'I';
    		num = num - 1;
    	}
        return res;
    }
};

int main(int argc, char ** argv)
{
	// string input = "";
	// int i=0;
	// while(argv[1][i] != '\0')
	// {
	// 	input += argv[1][i];
	// 	i++;
	// }
	Solution * mySolution = new Solution();
	cout<<mySolution->intToRoman(std::atoi (argv[1]))<<endl;
	delete mySolution;

	return 0;
}