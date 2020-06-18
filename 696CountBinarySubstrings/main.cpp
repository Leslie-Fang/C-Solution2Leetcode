#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
    	int res = 0;
    	if(s.size()<=1){
    		return 0;
    	}
    	vector<int> count;
    	int cur_count = 0;
    	char last = s[0];
    	//char cur = s[0];
    	for(auto i:s){
    		if(i == last){
    			cur_count ++;
    		}else{
    			count.push_back(cur_count);
    			cur_count = 1;
    		}
    		last = i;
    	}
    	count.push_back(cur_count);
    	int last_item = count[0];
    	bool skip_first = true;
    	for(auto item:count){
    		//cout<<item<<endl;
    		if(skip_first){
    			skip_first = false;
    		}else{
    			res += min(item, last_item);
    		}
    		last_item = item;
    	}

    	return res;
    }
};

int main(int argc, char ** argv){
	string input;
	getline(cin, input);
	Solution * mySolution = new Solution();
	cout<<mySolution->countBinarySubstrings(input)<<endl;

	delete mySolution;
	return 0;
}