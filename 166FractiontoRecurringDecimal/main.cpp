#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res = "";
        bool fraction_hit = false;
        long tmp = numerator;
        long d_tmp = denominator;
        vector<int> parallel_list;
        vector<int>::iterator it;
        bool negative = false;
        if(tmp == 0){
        	return "0";
        }
        if(tmp < 0 && d_tmp < 0 ){
        	tmp = -tmp;
        	d_tmp = -d_tmp;
        	negative = false;
        }else if(tmp < 0){
        	tmp = -tmp;
        	negative = true;
        }else if(d_tmp < 0){
        	d_tmp = -d_tmp;
        	negative = true;
        }
        while(tmp != 0){
        	it = find(parallel_list.begin(), parallel_list.end(), tmp);
        	if(it != parallel_list.end()){
        		int count = it - parallel_list.begin() + 1;
        		count += res.find(".");
        		if(res[0] == '0'){
        			res = res.insert(count,"(");
        			res += ')';
        		}else{
        			res = res.insert(count,"(");
        			res += ')';
        		}
        		break;
        	}else{
        		if(res.find(".") != res.npos){
        			parallel_list.push_back(tmp);
        		}
        	}

        	//cout<<tmp<<" -----"<<endl;
        	if(tmp >= d_tmp){
        		res += to_string(tmp/d_tmp);
        		tmp = tmp % d_tmp;
        		if(tmp<d_tmp && !fraction_hit && tmp != 0){
        			res += ".";
        			fraction_hit = true;
        		}
        		tmp = tmp * 10;
        	}else{
        		if(!fraction_hit){
        			if(res == ""){
        				res += "0.";
        			}else{
        				res += ".";
        			}
        			fraction_hit = true;
        		}else{
        			res += "0";
        		}
        		tmp = tmp * 10;
        	}
        }
        if(negative){
        	res = res.insert(0,"-");
        }
        return res;
    }
};

int main(int argc, char **argv){
	string input1;
	string input2;
	getline(cin, input1);
	getline(cin, input2);

	Solution * mySolution = new Solution();
	cout<<mySolution->fractionToDecimal(stoi(input1), stoi(input2))<<endl;

	return 0;
}