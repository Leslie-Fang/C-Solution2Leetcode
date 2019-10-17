#include <iostream>
#include <string>
using namespace std;
//2461016264268110179
class Solution {
public:
    bool isAdditiveNumber(string& num) {
    	if(num.size()<3)
    	{
    		return false;
    	}
    	unsigned long count = 0;
    	string temp;
    	unsigned long first = 0;
    	while(count <= (num.size()-3))
    	{
    		temp = num.substr(0,count+1);
    		if(temp.size() > num.size()-(count))
    		{
    			return false;
    		}
    		//cout<<"1:"<<temp<<endl;
    		if(stoull(temp) == 0)
    		{
    			first = 0;
    		}else
    		{
	    		unsigned long i = 0;
	    		for(i=0;i<temp.size();i++)
	    		{
	    			if(temp[i] != '0')
	    			{
	    				break;
	    			}
	    		}
	    		if(i != 0)
	    		{
	    			count += 1;
	    			continue;
	    		}
	    		first = stoull(temp);
    		}    		
    		if(DP(first, num, count+1))
    		{
    			return true;
    		}
    		count += 1;
    	}
    	return false;
    }

    bool DP(unsigned long first, string & num, unsigned long start)
    {
    	unsigned long count = 0;
    	string temp;
    	unsigned long second = 0;
    	while((count+start) <= num.size()-2)
    	{
    		temp = num.substr(start,count+1);
    		if(temp.size() > num.size()-(count+start) )
    		{
    			return false;
    		}
    		cout<<"2:"<<temp<<endl;
    		if(stoull(temp) == 0)
    		{
    			second = 0;
    		}else
    		{
	    		unsigned long i = 0;
	    		for(i=0;i<temp.size();i++)
	    		{
	    			if(temp[i] != '0')
	    			{
	    				break;
	    			}
	    		}
	    		if(i != 0)
	    		{
	    			count += 1;
	    			continue;
	    		}
	    		second = stoull(temp);
    		}

    		unsigned long subres = first + second;
    		if(find(second,subres,num,count+start+1))
    		{
    			return true;
    		}
    		count += 1;
    	}
    	return false;
    }
    bool find(unsigned long second, unsigned long subres,string & num, unsigned long start)
    {
    	unsigned long count = 0;
    	string temp;
    	unsigned long thrid = 0;
    	while((count+start) <= num.size()-1)
    	{
    		temp = num.substr(start,count+1);
    		if(stoull(temp) > subres)
    		{
    			return false;
    		}
    		cout<<"3:"<<temp<<endl;
    		if(stoull(temp) == 0)
    		{
    			thrid = 0;
    		}else
    		{
	    		unsigned long i = 0;
	    		for(i=0;i<temp.size();i++)
	    		{
	    			if(temp[i] != '0')
	    			{
	    				break;
	    			}
	    		}
	    		if(i != 0)
	    		{
	    			count += 1;
	    			continue;
	    		}
	    		thrid = stoull(temp);
    		}
    		if(subres == thrid)
    		{
    			if(count+start+1 == num.size())
    			{
    				return true;
    			}
    			cout<<"Find"<<endl;
    			return find(thrid,second+thrid,num,count+start+1);
    		}
    		count += 1;
    	}
    	return false;
    }
};

int main(){
	string input;
	getline(cin,input);
	Solution * mySolution = new Solution();
	cout<<mySolution->isAdditiveNumber(input)<<endl;
	delete mySolution;	
}