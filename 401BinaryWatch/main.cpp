#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

class Solution {
public:
	void get(int total, int num, int cur, int index, vector<string> &res, int tmp, bool hour){
		if(total <= index && cur<num){
			return;
		}else if(cur == num){
			if(!hour && tmp<10){
				res.push_back("0"+to_string(tmp));
			}else if(hour && tmp>=12){
				return;
			}else if(!hour && tmp>=60){
				return;
			}else{
				res.push_back(to_string(tmp));
			}
			return;
		}

		get(total, num, cur+1, index+1, res, tmp+pow(2,index), hour);
		get(total, num, cur, index+1, res, tmp, hour);

		return;
	}

    vector<string> readBinaryWatch(int num) {
    	vector<string> res;
    	vector<string> temp1;
    	vector<string> temp2;
    	for(int i=0;i<=num;i++){
    		temp1.clear();
    		temp2.clear();
    		get(4, i, 0, 0, temp1, 0, true);
    		get(6, num-i, 0, 0, temp2, 0, false);
    		for(auto item1:temp1){
    			for(auto item2:temp2){
    				res.push_back(item1+":"+item2);
    			}
    		}
    	}
    	return res;
    }
};

int main(int argc, char ** argv){
	Solution * mySolution = new Solution();
	string input;
	getline(cin, input);
	vector<string> res = mySolution->readBinaryWatch(stoi(input));
	for(auto item:res){
		cout<<item<<endl;
	}
	delete mySolution;
	return 0;
}