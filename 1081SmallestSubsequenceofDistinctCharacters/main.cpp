#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string smallestSubsequence(string text) {
    	string s = text;
    	string res="";
		int cnt[26] = {}, used[26] = {};
	  for (auto ch : s) ++cnt[ch - 'a'];
	  for (auto ch : s) {
	    --cnt[ch - 'a'];
	    if (used[ch - 'a']++ > 0) continue;
	    while (!res.empty() && res.back() > ch && cnt[res.back() - 'a'] > 0) {
	      used[res.back() - 'a'] = 0;
	      res.pop_back();
	    }
	    res.push_back(ch);
	  }
	  return res;    
    }
};

int main(int argc, char ** argv)
{
	Solution * mySolution = new Solution();
	cout<<mySolution->smallestSubsequence("ddeeeccdce")<<endl;
	return 0;
}