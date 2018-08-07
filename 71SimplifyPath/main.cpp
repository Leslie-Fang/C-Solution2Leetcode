#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path);
};

int main(int argc, char const *argv[])
{
	string input="/..";
	Solution * my_Solution=new Solution();
	cout<<my_Solution->simplifyPath(input)<<endl;
	return 0;
}

string Solution::simplifyPath(string path){
	if(path.length() == 0){
		return "";
	}
	vector<string> paths;
	string sub_path="";
	bool count=false;
	for(int i=0;i<path.length();i++){
		if(path[i] == '/'){
			if(sub_path == ""){
				continue;
			}else if(sub_path == "."){
				sub_path="";
				continue;
			}else if(sub_path == ".."){
				if(paths.size() !=0 ){
					paths.pop_back();
				}
				sub_path="";
			}else{
				paths.push_back(sub_path);
				sub_path="";
			}
		}else{
			sub_path += path[i];
		}
	}
	if(sub_path != ""){
		if(sub_path == ".."){
				if(paths.size() !=0 ){
					paths.pop_back();
				}
		}else if(sub_path != "."){
			paths.push_back(sub_path);
		}
	}
	string res="/";
	for(int i=0;i<paths.size();i++){
		res += paths[i];
		if(i != paths.size()-1)
		res += "/";
	}

	return res;
}