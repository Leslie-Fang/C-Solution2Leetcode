#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
    	vector<string> temp;
    	int min = 0;
    	int compare_length = s.size();
    	bool early_stop = false;
        int index = 0;
    	int compare_it_length = 0;
    	for(vector<string>::iterator it=d.begin(); it != d.end();it++)
    	{
    		early_stop = false;
    		index = 0;
    		compare_it_length = (*it).size();
    		if((*it).size() > compare_length)
    		{
    			continue;
    		}
    		for(int i=0;i<compare_it_length;i++)
    		{
    			while((*it)[i] != s[index])
    			{
    				index += 1;
    				if((compare_it_length - i) > (compare_length-index)  || index >= compare_length)
    				{
    					early_stop = true;
    					break;
    				}
    			}
    			index += 1;
    			if(early_stop)
    			{
    				break;
    			}
    		}
    		if(early_stop)
    		{
    			continue;
    		}else{
    			if(min == compare_it_length)
    			{
    				temp.push_back(*it);
    			}else if(min < compare_it_length)
    			{
    				temp.clear();
    				temp.push_back(*it);
    				min = compare_it_length;
    			}else
    			{
    				continue;
    			}
    		}
    	}
    	if(temp.size() == 0)
    	{
    		return "";
    	}
    	else{
			sort(temp.begin(),temp.end());
			return(temp[0]);
    	}
    	return "";
    }
};

int main(int argc, char ** argv){
	string a[4] = {"ale","apple","monkey","plea"};
	vector<string> input(a,a+4);
	Solution * mySolution = new Solution();
	cout<<mySolution->findLongestWord("abpcplea",input)<<endl;
	delete mySolution;
	return 1;

}