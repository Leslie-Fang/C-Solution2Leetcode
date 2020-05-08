#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.length() <= p.length()) {
        	return res;
        }
        for(int i=0;i<=s.length() - p.length();i++) {
        	if(isAnagrams(s,i,p))
        	{
        		res.push_back(i);
        	}
        }
        return res;
    }
};

int main(int argc, char ** argv) {
	string input1;
	string input2;
	getline(cin, input1);
	getline(cin, input2);
	Solution * mySolution = new Solution();
	vector<int> res = mySolution->findAnagrams(input1, input2);
	for(auto item : res) {
		cout<<item<<endl;
	}
	return 0;
}