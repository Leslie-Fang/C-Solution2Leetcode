//
// Created by leslie-fang on 2017/7/13.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string countAndSay(int n) {
    if( n == 1){
        return "1";
    }
    string input="1";
    string res="11";
    string temp="";
    int i=1;
    while(i<n){
        int j=0;
        char cinputchar=input[0];
        int cnum=0;
        while(j<input.length()){
            if(cinputchar == input[j]){
                cout<<"equal should add 1"<<endl;
                cnum++;
            }else{
                cout<<"to_string(cnum): "<<to_string(cnum)<<endl;
                temp +=to_string(cnum) + cinputchar;
                cinputchar=input[j];
                cnum = 1;
            }
            //cout<<input[j]<<endl;
            j++;
            if(j == input.length()){
                cout<<"to_string(cnum): "<<to_string(cnum)<<endl;
                temp +=to_string(cnum) + cinputchar;
            }
        }
        res = temp;
        temp = "";
        cout<<"The round is:"<<i<<endl;
        cout<<"input is:"<<input<<endl;
        cout<<"res is:"<<res<<endl;

        input = res;

        i++;
    }

    return res;
}

int main(){
    cout<<countAndSay(5)<<endl;
    cout<<"hello world!"<<endl;
    return 0;
}
