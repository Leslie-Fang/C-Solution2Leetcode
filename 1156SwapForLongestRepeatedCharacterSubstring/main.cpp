#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
	map<char, int> allword;
	vector<pair<char,int> > linkword;
    int maxRepOpt1(string text) {
    	if(text.length()<=0)
    	{
    		return 0;
    	}
    	char last=text[0];
    	int count = 0;
    	map<char, int>::iterator itr;
    	for(int i=0;i<text.length();i++)
    	{
    		itr = allword.find(text[i]);
    		if(itr == allword.end())
    		{
    			allword.insert(pair<char,int>(text[i],1));
    		}else{
    			itr->second +=1;
    		}
    		if(text[i] == last)
    		{
    			count +=1;
    		}else
    		{
    			linkword.push_back(pair<char,int>(last,count));
    			count = 1;
    			last=text[i];
    		}
    	}
    	linkword.push_back(pair<char,int>(last,count));
    	

    	int res = linkword.begin()->second;
	    int total = 0;
	   	int compare = 0;
	   	map<char, int>::iterator allword_it = allword.begin();
    	for(vector<pair<char,int> >::iterator it = linkword.begin(); it != linkword.end();it++)
    	{
    		if(it->second > res)
    		{
    			res = it->second;
    		}
    		allword_it = allword.find(it->first);
    		if( (allword_it->second > it->second) && (it->second+1 > res))
    		{
    			res = it->second+1;
    		}
    		if(it >= linkword.end()-2)
    		{
    			continue;
    		}
    		if( (it->first == (it+2)->first) && ((it+1)->second == 1))
    		{
	    		total = allword_it->second;
	    		compare = it->second + (it+2)->second;
	    		if(total > (it->second + (it+2)->second))
	    		{
					compare += 1;
	    		}
	    		if(compare > res)
	    		{
	    			res = compare;
	    		}
    		}
    	}        
        return res;
    }
    ~ Solution()
    {
    	allword.clear();
    	linkword.clear();
    }
};

int main(int argc, char ** argv)
{
	Solution * mySolution = new Solution();
	string input;
	getline(cin,input);
	cout<<mySolution->maxRepOpt1(input)<<endl;
	delete mySolution;
	return 0;
}