#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    	int res = 0;

        map<int, int> hashAB;
        map<int, int> hashCD;

        int tmp = 0;
        map<int, int>::iterator it;
        for(auto iA:A){
            for(auto iB:B){
                tmp = iA+iB;
                it = hashAB.find(tmp);
                if(it == hashAB.end()){
                    hashAB.insert(pair<int, int>(tmp, 1));
                }else{
                    it->second ++;
                }
            }
        }
        for(auto iC:C){
            for(auto iD:D){
                tmp = iC+iD;
                it = hashCD.find(tmp);
                if(it == hashCD.end()){
                    hashCD.insert(pair<int, int>(tmp, 1));
                }else{
                    it->second ++;
                }
            }
        }
        map<int, int>::iterator it2;
        for(it = hashAB.begin();it != hashAB.end();it++){
            it2 = hashCD.find(-it->first);
            if(it2 != hashCD.end()){
                res += it->second * it2->second;
            }
        }
    	return res;
    }
};

int main(int argc, char ** argv){

	return 0;
}