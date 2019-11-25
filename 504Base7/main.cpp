#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string convertToBase7(int num) {
    	string res = "";
    	if(num == 0)
    	{
    		return "0";
    	}else if(num < 0)
    	{
    		num = -num;
    		res += '-';
    	}
    	// cout<<num<<endl;
    	int left = num;
    	vector<int> result;
    	while(1)
    	{
    		// cout<<left<<endl;
    		result.push_back(left%7);
    		left = left/7;
    		if(left == 0)
    		{
    			break;
    		}
    	}
    	// cout<<result.size()<<endl;
    	for(int i=result.size()-1;i>=0;i--)
    	{
    		cout<<result[i]<<endl;
    		res += to_string(result[i]);
    	}
    	return res;      
    }
};

int main(int argc, char **argv)
{
	string input;
	getline(cin, input);
	Solution * mySolution = new Solution();
	cout<< mySolution->convertToBase7(stoi(input)) <<endl;
	return 1;
}