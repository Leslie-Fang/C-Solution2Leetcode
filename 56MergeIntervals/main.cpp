#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // static bool cmp(vector<int> a,vector<int> b){
    //     return a[0]<b[0];
    // }
    vector<vector<int> > merge(vector<vector<int>>& intervals) {
    	//Sort
        int size = intervals.size();
        if(size == 0){
            return intervals;
        }
        vector<vector<int> > res;
        sort(intervals.begin(),intervals.begin()+size);
        vector<vector<int>>::iterator worker;
        vector<vector<int>>::iterator cmp;

        worker = intervals.begin();
        cmp = intervals.begin();
        cmp ++;

        while(1){
            if(cmp!=intervals.end()){
                if((*cmp)[0] > (*worker)[1]){
                    res.push_back(*worker);
                    worker = cmp;
                    cmp ++;
                }else if((*cmp)[1]>(*worker)[1]){
                    (*worker)[1] = (*cmp)[1];
                    cmp ++;

                }else if((*cmp)[1]<=(*worker)[1]){
                    cmp ++;
                }

            }else{
                cout<<"prepare to break"<<endl;
                break;
            }
        }
        res.push_back(*worker);
        return res;
    }
};

int main(int argc, char ** argv)
{
	Solution * mySolution = new Solution();

	delete mySolution;
	return 1;

}