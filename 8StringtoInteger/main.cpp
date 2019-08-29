#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str);
};

int main(int argc,char ** argv){
	Solution *mySolution = new Solution();
	string input="8+ 0";
	cout<<mySolution->myAtoi(input)<<endl;
	return 1;
}

int Solution::myAtoi(string str){
	int l=str.length();
	bool negative=false;
	long res=0;
	int returnValue;
	bool check=false;
	bool start=false;
	for(int i=0;i<l;i++){
		if(!check){
			if(str[i] == ' '){
				if(start){
					break;
				}
				continue;
			}else if(str[i] == '+'){
				if(start){
					break;
				}
				check=true;
				continue;
			}else if(str[i] == '-'){
				if(start){
					break;
				}
				check=true;
				negative=true;
			}else if(str[i] >= '0' && str[i] <= '9'){
				res =res*10+(int)(str[i]-'0');
				start=true;
				if(res>=2147483647 && !negative){
					return 2147483647;
				}else if(res>=2147483648 && negative){
					return -2147483648;
				}
			}else{
				break;
			}			
		}else{
			if(str[i] == ' ' || str[i] == '-' || str[i] == '+'){
				if(start){
					break;
				}
				return 0;
			}else if(str[i] >= '0' && str[i] <= '9'){
				res =res*10+(int)(str[i]-'0');
								start=true;
				if(res>=2147483647 && !negative){
					return 2147483647;
				}else if(res>=2147483648 && negative){
					return -2147483648;
				}
			}else{
				break;
			}
		}
	}
	if(negative){
		res=-res;
	}
	return res;
}