#include <iostream>
#include <vector>
using namespace std;

 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals);
};

int main(){
	cout<<"Hello"<<endl;
	Solution * mySolution = new Solution();
	Interval test[2] = {*(new Interval(1,2)),*(new Interval(2,3))};
	vector<Interval> input(begin(test),end(test));
	vector<int> res=mySolution->findRightInterval(input);
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<endl;
	}
	return 1;
}

 vector<int> Solution::findRightInterval(vector<Interval>& intervals){
 	int test[2] = {1,2};
 	 vector<int> res(begin(test),end(test));
 	 return res;
 }

 void combineSort(){

 }