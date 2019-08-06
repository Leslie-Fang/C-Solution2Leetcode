#include <iostream>
#include <vector>
using namespace std;

int row[26] = {0,0,0,0,0,1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4,5};
int column[26] = {0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0};
int base = 97;
class Solution {
public:
    string alphabetBoardPath(string target) {
        int len = target.size();
        int cr = 0;
        int cl = 0;
        int tr = 0;
        int tl = 0;
        int label = 0;
        int ud = 0;
        int lr = 0;
        string res = "";
        for(int i=0;i<len;i++)
        {
        	label = int(target[i]) - base;
        	tr = row[label];
        	tl = column[label];
        	lr = tl - cl;
        	ud = tr - cr;
        	if(lr > 0 && ud <0)
        	{
        		while(ud < 0)
	        	{
	        		res += "U";
	        		ud ++;
	        	}
	        	while(ud > 0)
	        	{
	        		res += "D";
	        		ud --;
	        	}
	        	while(lr < 0)
	        	{
	        		res += "L";
	        		lr++;
	        	}
	        	while(lr > 0)
	        	{
	        		res += "R";
	        		lr--;
	        	}
        	}else
        	{
	        	while(lr < 0)
	        	{
	        		res += "L";
	        		lr++;
	        	}
	        	while(lr > 0)
	        	{
	        		res += "R";
	        		lr--;
	        	}
	        	while(ud < 0)
	        	{
	        		res += "U";
	        		ud ++;
	        	}
	        	while(ud > 0)
	        	{
	        		res += "D";
	        		ud --;
	        	}
        	}


        	cr = tr;
        	cl = tl;
        	res += "!";
        }

        return res;
    }
};

int main(int argc, char ** argv)
{
	Solution * mySolution = new Solution();
	cout<<mySolution->alphabetBoardPath("zdz")<<endl;
	
	return 0;
}