#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s);
    void sub_partition(string s,vector<string> temp, vector<vector<string> > & res);
    bool is_palindrome(string s);
};

int main(int argc, char ** argv){
	Solution * mySolution = new Solution();
	vector<vector<string> > res=mySolution->partition("aabb");
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<endl;
		}
	}
	return 1;
}

vector<vector<string> > Solution::partition(string s){
	vector<vector<string> > res;
	vector<string> temp;
	sub_partition(s,temp,res);
	return res;

}

void Solution::sub_partition(string s,vector<string> temp, vector<vector<string> > & res){
	if(s.size() == 1){
		temp.push_back(s);
		res.push_back(temp);
		return;
	}else if(s.size() == 0){
		res.push_back(temp);
		return;
	}
	for(int i=0;i<s.size();i++){
		if(is_palindrome(s.substr(0,i+1))){
			temp.push_back(s.substr(0,i+1));
			sub_partition(s.substr(i+1,s.size()-i-1),temp,res);
			temp.pop_back();
		}
	}
	return ;
}

bool Solution::is_palindrome(string s){
	int i=0;
	int j=s.size()-1;
	while(i<j){
		if(s[i] != s[j]){
			return false;
		}
		i++;
		j--;
	}
	return true;
}