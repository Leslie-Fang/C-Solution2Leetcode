#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int > > combine(int n, int k);
    void sub_combine(int start, int n, int k, vector<int> temp, vector<vector<int> > &res);
};

int main(int argc,char ** argv){
	Solution *mySolution = new Solution();
	vector<vector<int> > res = mySolution->combine(4,3);
	for(int i=0;i<res.size();i++){
		cout<<"-------------"<<endl;
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<endl;
		}
	}
	return 0;
}

vector<vector<int> > Solution::combine(int n, int k){
	vector<vector<int > > res;
	vector<int> temp;
	sub_combine(1,n,k,temp,res);
	return res;
}

void Solution::sub_combine(int start, int n, int k, vector<int> temp, vector<vector<int> > &res){
	if(k == 0){
		res.push_back(temp);
		return;
	}
	for(int i=start;i<=n-k+1;i++){
		temp.push_back(i);
		sub_combine(i+1,n,k-1,temp,res);
		temp.pop_back();
	}
	return;
}