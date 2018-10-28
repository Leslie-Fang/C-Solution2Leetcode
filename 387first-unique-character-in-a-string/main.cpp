#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
    int firstUniqChar(string s);
};

int main()
{
  string input;
  getline(cin,input);
	Solution * mySolution = new Solution();
	cout<<mySolution->firstUniqChar(input)<<endl;
	return 0;

}

int Solution::firstUniqChar(string s)
{    
    if(s.size() == 0)
    {
      return -1;
    }
    map<char, int> resultMap;  
    vector<char> repeted;
    for(int i=0;i<s.size();i++)
    {
      if(find(repeted.begin(),repeted.end(),s[i]) == repeted.end())
      {
        repeted.push_back(s[i]);
        resultMap.insert(pair<char, int>(s[i], i));
      }else
      {
        if(resultMap.find(s[i]) != resultMap.end())
        {
          resultMap.erase(s[i]);
        }
      }
    } 
    if(resultMap.size() == 0)
    {
      return -1;
    }
    int first = s.size();
    for(map<char, int>::iterator iter=resultMap.begin();iter != resultMap.end();iter++)
    {
      if(iter->second < first)
      {
        first = iter->second;
      }

    }
    return first;
}