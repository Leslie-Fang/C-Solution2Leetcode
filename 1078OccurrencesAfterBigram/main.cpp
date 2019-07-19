#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second)
    {
        vector<string> res;

		size_t pos = 0;
		string token;
		std::string delimiter = " ";
		bool first_found = false;
		bool second_found = false;
		while ((pos = text.find(delimiter)) != std::string::npos){
		    token = text.substr(0, pos);
		    //cout<<token<<endl;
			if(first_found == true && second_found ==true)
		    {
		    	//cout<<"---------------"<<endl;
		    	res.push_back(token);
		    	first_found = false;
		    	second_found = false;
		    	if(token == first)
		    	{
		    		first_found = true;
		    	}
		    }else if(!first_found && token==first)
		    {
		    	first_found = true;
		    }
		    else if(first_found && token==second)
		    {
		    	second_found = true;
		    }else if(first_found && token!=second && token!=first)
		    {
		    	first_found = false;
		    }
		    text.erase(0, pos + delimiter.length());
		}
		if(first_found == true && second_found ==true)
		{
			res.push_back(text);
		}
		// std::cout << s << std::endl;
		for(vector<string>::iterator it = res.begin();it != res.end();it++)
		{
			cout<<*it<<endl;
		}
        return res;
    }
};

int main()
{
	Solution * mySolution = new Solution();
	mySolution->findOcurrences("we we will we we will rock you","we","will");
	return 0;
}