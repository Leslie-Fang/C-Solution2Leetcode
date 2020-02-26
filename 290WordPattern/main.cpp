#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
	void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
	{
	  std::string::size_type pos1, pos2;
	  pos2 = s.find(c);
	  pos1 = 0;
	  while(std::string::npos != pos2)
	  {
	    v.push_back(s.substr(pos1, pos2-pos1));
	 
	    pos1 = pos2 + c.size();
	    pos2 = s.find(c, pos1);
	  }
	  if(pos1 != s.length())
	    v.push_back(s.substr(pos1));
	}
    bool wordPattern(string pattern, string str) {
        map<char, int> mymap1;
        map<string, int> mymap2;
        map<char, int>::iterator it1;
        map<string, int>::iterator it2;
        int index = 1;

        std::vector<std::string> input3;
		SplitString(str, input3, " ");
		if(pattern.length() != input3.size())
		{
			return false;
		}
        for(int i=0;i<pattern.length();i++)
        {
        	if(mymap1.size() == 0)
        	{
        		mymap1.insert(pair<char, int>(pattern[i], index));
        		mymap2.insert(pair<string, int>(input3[i], index));
        		index += 1;
        	}else
        	{
        		it1 = mymap1.find(pattern[i]);
        		if(it1 == mymap1.end())
        		{
        			if(mymap2.find(input3[i]) != mymap2.end())
        			{
        				return false;
        			}
        			else
        			{
		        		mymap1.insert(pair<char, int>(pattern[i], index));
		        		mymap2.insert(pair<string, int>(input3[i], index));
		        		index += 1;
        			}
        		}else
        		{
        			it2 = mymap2.find(input3[i]);
        			if(it2 == mymap2.end())
        			{
        				return false;
        			}else
        			{
        				if(it1->second != it2->second)
        				{
        					return false;
        				}
        			}
        		}
        	}
        }

        return true;
    }
};

int main(int argc, char ** argv)
{
 string input1;
 string input2;
 getline(cin, input1);
 getline(cin, input2);
 Solution * mySolution;
 cout<<mySolution->wordPattern(input1, input2)<<endl;
 return 0;

}