#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
  string decodeString(string s);
  string subDecodeString(string s);
private:
  vector<string> analyze;
};

int main()
{
  string input;
  getline(cin,input);
	Solution * mySolution = new Solution();
	cout<<mySolution->decodeString(input)<<endl;
	return 0;

}

string Solution::decodeString(string s)
{    
  return subDecodeString(s);
}

string Solution::subDecodeString(string s)
{
  //cout<<s.size()<<endl;
  int index = 0;
  analyze.push_back("");
  for(int i=0;i<s.size();i++)
  {
    //cout<<"---------"<<endl;
    if(s[i] != '[' and s[i] != ']')
    {
     // cout<<1<<"--"<<s[i]<<endl;
      analyze[index] +=  s[i];
    }
    else if(s[i] == '[')
    {
      //cout<<2<<"--"<<s[i]<<endl;
      analyze.push_back("");
      index += 1;
      //analyze[index] +=  s[i];
    }
    else
    {
      // cout<<3<<"--"<<s[i]<<endl;
      int last_index = index-1;
      string substring = analyze[last_index];
      int repeted_num = 0;
      int nums = 0;
      for(int j=substring.size()-1;j>=0;j--)
      {
        if(int(substring[j])>=48 && int(substring[j])<=57)
        {
          nums += 1;
          int addnum = (int(substring[j])-48);
          for(int k=0;k<substring.size()-1-j;k++)
          {
            addnum = addnum*10;
          }
          repeted_num += addnum;
        }
      }
      analyze[last_index] = analyze[last_index].substr(0,substring.size()-nums);
      for(int j=0;j<repeted_num;j++)
      {
        analyze[last_index] += analyze[index];
      }
      analyze.pop_back();
      index = index - 1;
    }
  }
  //cout<<analyze[0]<<endl;
  return analyze[0];
}




