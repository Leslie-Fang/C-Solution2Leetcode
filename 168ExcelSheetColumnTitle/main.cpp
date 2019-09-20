#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
    	string res;
    	vector<int> temp;
    	while(n/26 != 0)
    	{
    		if(n % 26 == 0)
    		{
    			temp.push_back(26);
                if(n == 26)
                {
                    n = n - 26;
                }else
                {
                    n = n/26-1;
                }
    		}else
            {
                temp.push_back(n%26);
                n = n/26;
            }
    	}
    	if(n != 0)
    	{
    		temp.push_back(n%26);
    	}
    	
    	
    	for(int i=temp.size()-1;i>=0;i--)
    	{
    		cout<<temp[i]<<endl;
    		res += char(64+temp[i]);
    	}
    	
    	return res;
        
    }
};

int main(int argc, char ** argv)
{
	string input;
	getline(cin,input);
	stringstream convt(input);
	int x;
	convt >> x;
	Solution * mySolution = new Solution();
	cout<<mySolution->convertToTitle(x)<<endl;
	delete mySolution;
	return 1;

}