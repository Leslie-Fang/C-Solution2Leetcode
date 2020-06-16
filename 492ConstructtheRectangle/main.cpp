#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:

    vector<int> constructRectangle(int area) {
        vector<int> res;
        float ss = sqrt(area);
        int start = int(ss);
        //cout<<start<<endl;
        int L = start;
        int W = start;
        while(area % L != 0 || L < area/L){
        	L = L + 1;
        }
        res.push_back(L);
        res.push_back(area/L);


        return res;
    }
};

int main(int argc, char ** argv){
	string sinput;
	getline(cin, sinput);
	int input = stoi(sinput);
	Solution * mySolution = new Solution();
	//cout<<input<<endl;
	vector<int> res = mySolution->constructRectangle(input);
	for(auto element:res){
		cout<<element<<endl;
	}
	delete mySolution;

	return 0;
}