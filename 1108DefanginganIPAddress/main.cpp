#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
    	int len = address.size();
    	vector<char> temp;
    	for(int i=0;i<len;i++)
    	{
    		// cout<<address[i]<<endl;
    		if(address[i] != '.')
    		{
    			temp.push_back(address[i]);
    		}else
    		{
    			temp.push_back('[');
    			temp.push_back('.');
    			temp.push_back(']');
    		}
    	}
    	string res;
    	for(int i=0;i<temp.size();i++)
    	{
    		res += temp[i];
    	}
        return res;
    }
};

int main(int argc, char ** argv)
{
	Solution * mySolution = new Solution();
	cout<<mySolution->defangIPaddr("255.100.50.0")<<endl;
	return 0;
}