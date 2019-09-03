#include <iostream>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
    	map<char, int> mylist = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    	int length = s.length();
    	int res = 0;
    	int i = 0;
    	while(i<length-1)
    	{
    		if((s[i] == 'I' && s[i+1] == 'X') || (s[i] == 'I' && s[i+1] == 'V'))
    		{
    			res += mylist[s[i+1]]-mylist['I'];
    			i += 1;
    		}else if((s[i] == 'X' && s[i+1] == 'L') || (s[i] == 'X' && s[i+1] == 'C'))
    		{
    			res += mylist[s[i+1]]-mylist['X'];
    			i += 1;
    		}else if((s[i] == 'C' && s[i+1] == 'D') || (s[i] == 'C' && s[i+1] == 'M'))
    		{
    			res += mylist[s[i+1]]-mylist['C'];
    			i += 1;
    		}
    		else
    		{
    			res += mylist[s[i]];
    		}
    		i += 1;
    	}
    	if(i == length-1)
    	{
    		res += mylist[s[i]];
    	}
        return res;
    }
};

int main(int argc, char ** argv)
{
	//cout << sizeof(argv[1]) <<endl;
	int i = 0;
	string input = "";
	while(argv[1][i] != '\0')
	{
		input += argv[1][i];
		i++;
	}
	cout << input <<endl;
	Solution * mySolution = new Solution();
	cout<<mySolution->romanToInt(input)<<endl;
	delete mySolution;
}