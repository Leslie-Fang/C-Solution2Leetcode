#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	vector<int> DP(string expression, int &count){
		vector<int> element;
		while(true)
		{
			if(expression[count] == '|' || expression[count] == '&' || expression[count] == '!')
			{
    			char sign = expression[count];
    			count += 2;
    			vector<int> res = DP(expression, count);
    			if(sign == '!')
    			{
    				element.push_back(res[0]==0?1:0);
    			}else if(sign == '&')
    			{
    				bool find = false;
    				for(vector<int>::iterator it=res.begin();it!=res.end();it++)
    				{
    					//cout<<*it<<endl;
    					if(*it == 0)
    					{
    						find = true;
    						break;
    					}
    				}
    				if(find)
    				{
						element.push_back(0);
    				}else
    				{
						element.push_back(1);
    				}
    				
    			}else{
    				bool find = false;
    				for(vector<int>::iterator it=res.begin();it!=res.end();it++)
    				{
    					if(*it == 1)
    					{
    						find = true;
    						break;
    					}
    				}
    				if(find)
    				{
						element.push_back(1);
    				}else
    				{
						element.push_back(0);
    				}
    			}
			}else if(expression[count] == 't')
			{
				element.push_back(1);
				count += 1;
			}else if(expression[count] == 'f')
			{
				element.push_back(0);
				count += 1;
			}else if(expression[count] == ',')
			{
				count += 1;
			}
			else if(expression[count] == ')')
			{
				count += 1;
				break;
			}
		}
		//calculation
		return element;
	}
    bool parseBoolExpr(string expression) {
    	int count = 0;
    	if(expression.length() == 0 || expression[0] == 't')
    	{
    		return true;
    	}else if(expression[0] == 'f')
    	{
    		return false;
    	}
    	vector<int> element;
    	while(count<expression.length())
    	{
    		if(expression[count] == '|' || expression[count] == '&' || expression[count] == '!')
    		{
    			char sign = expression[count];
    			count += 2;
    			vector<int> res = DP(expression,count);
    			if(sign == '!')
    			{
    				element.push_back(res[0]==0?1:0);
    			}else if(sign == '&')
    			{
    				for(vector<int>::iterator it=res.begin();it!=res.end();it++)
    				{
    					if(*it == 0)
    					{
    						element.push_back(0);
    						break;
    					}
    				}
    				element.push_back(1);
    			}else{
    				for(vector<int>::iterator it=res.begin();it!=res.end();it++)
    				{
    					// cout<<*it<<endl;
    					if(*it == 1)
    					{
    						element.push_back(1);
    						break;
    					}
    				}
    				element.push_back(0);
    			}
    		}
    	}
        return element[0];
    }
};

int main()
{
	string input;
	getline(cin,input);
	Solution * mySolution = new Solution();
	cout<<mySolution->parseBoolExpr(input)<<endl;
	delete mySolution;
	return 1;
}