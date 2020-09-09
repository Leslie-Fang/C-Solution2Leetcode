#include <iostream>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int res = 0;
    	int item_number = citations.size();
    	//sort(citations.begin(),citations.end());
    	for(int i=item_number;i>=0;i--){

    		int cbase = i;
    		//int split_point = item_number-cbase >= 0 ? item_number-cbase : 0;
    		int split_point = item_number-cbase;

    		if(split_point >= 1){
    			if(citations[split_point-1] > cbase){
    				continue;
    			}
    		}

    		if(item_number > split_point){
    			if( citations[split_point] < cbase){
	    			continue;
	    		}
    		}

    		res = cbase;
    		break;
    	}

    	return res;
    }
};

int main(int argc, char ** argv){

}