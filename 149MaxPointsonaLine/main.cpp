#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
    	if(points.size() <= 2){
    		return points.size();
    	}
    	int res = 2;
    	for(auto point:points){
    		int same_point = 0;
    		map<string, int> mymap;
    		map<string, int>::iterator it;
    		for(auto point2:points){
    			if(point2[0] == point[0] && point2[1] == point[1]){
    				same_point ++;
    			}else{
    				string key;
    				if(point2[0] == point[0]){
    					key = "inf";
    				}else{
						key = to_string((double(point2[1] - point[1]))/(point2[0] - point[0]));
    				}
    				it = mymap.find(key);
    				if(it == mymap.end()){
    					mymap[key] = 1;
    				}else{
    					it->second ++;
    				}
    			}
    		}
    		it = mymap.begin();
    		int max;
    		if(it != mymap.end()){
	    		max = it->second;
	    		while(it != mymap.end()){
	    			if(it->second>max){
	    				max = it->second;
	    			}
	    			it++;
	    		}
    		}else{
    			max = 0;
    		}

    		if(max + same_point > res){
    			res = max + same_point;
    		}
    	}
    	return res;
    }
};

int main(int argc, char ** argv){
	//[[0,0],[94911150,94911151],[94911151,94911152]]

	cout<<float(949111.51)/float(949111.50)<<endl;
	cout<<double(long(94911152))/double(long(94911151))<<endl;

	return 0;
}