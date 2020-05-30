#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
    	string res;
    	string temp;
    	map<char,int> mymap;
    	map<char,int>::iterator it;

    	for(int i=0;i<s.size();i++){
    		if(mymap.find(s[i]) == mymap.end()){
    			mymap.insert(pair<char,int>(s[i], i));
    		}else{
    			mymap[s[i]] = i;
    		}
    	}
    	for(int i=0;i<s.size();i++){
    		if(res.find(s[i]) == s.npos){
    			if(res.size() > 0){
    				temp.clear();
    				for(int j=0;j<res.size();j++){
	    				it = mymap.find(res[j]);

		    			if(it->second > i && (int(s[i]) < int(res[j]))){
		    				continue;
		    				//res.erase(res.begin()+j);
		    			}else{
		    				temp += res[j];
		    			}

    				}
    				res = temp;
    			}
    			res += s[i];
    			cout<<"-----------: "<<res<<endl;
    		}
    	}
    	return res;
    }
};

int main(int argc, char ** argv){
	Solution * mySolution = new Solution();
	string res = mySolution->removeDuplicateLetters("cbacdcbc");
	cout<<res<<endl;
	delete mySolution;
	return 0;
}