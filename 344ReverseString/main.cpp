#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseString(string s);
};
void swap(string & s,int i, int j);

int main(){
	cout<<"Hello"<<endl;
	Solution mySolution;
	cout<<mySolution.reverseString("hello")<<endl;
}

string Solution::reverseString(string s){
	int l=s.length();
	int i=0;
	int j=l-1;
	while(i<j){
		swap(s,i,j);
		i++;
		j--;
	}
	return s;
}

void swap(string & s,int i, int j){
	char temp = s[i];
	s[i] = s[j];
	s[j] = temp;
}

