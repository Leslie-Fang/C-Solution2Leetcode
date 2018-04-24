#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b);
    string reverse(string a);
};

int main(int argc, char** argv){
	Solution mySolution;
	cout<<mySolution.addBinary("1010","1011")<<endl;
}
string Solution::reverse(string a){
	string res="";
	for(int i=a.length()-1;i>=0;i--){
		res+=a[i];
	}
	return res;
}
string Solution::addBinary(string a, string b){
	//string res="";
	int minL=min(a.length(),b.length());
	int aL= a.length();
	int bL= b.length();
	int i=0;
	int ca=0,cb=0,cr=0;
	bool up=false;
	string res;
	while(i<minL){
		ca = int(a[aL-i-1])-int('0');
		cb = int(b[bL-i-1])-int('0');
		cr= ca+cb;
		if(up){
			cr +=1;
		}
		if(cr>=2){
			res+=to_string(cr-2);
			up = true;
		}else{
			res+=to_string(cr);
			up = false;
		}
		i++;
	}
	if(minL == aL){
		while(i<bL){
			cb = int(b[bL-i-1])-int('0');
			cout<<cb<<endl;
			cr = cb;
			if(up){
				cr+=1;
			}
			if(cr>=2){
				res+=to_string(cr-2);
				up = true;
			}else{
				res+=to_string(cr);
				up = false;
			}
			i++;
		}
	}else{
		while(i<aL){
			ca = int(a[aL-i-1])-int('0');
			cr = ca;
			if(up){
				cr+=1;
			}
			if(cr>=2){
				res+=to_string(cr-2);
				up = true;
			}else{
				res+=to_string(cr);
				up = false;
			}
			i++;
		}
	}
	if(up){
		res+='1';
	}
	return reverse(res);
}

