//
// Created by leslie-fang on 2017/8/14.
//
#include<iostream>
#include<vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    //use XOR
    //same number XOR return 0
    //any number XOR with 0 return the origin number
    //cout<<(2^10^2)<<endl; return 10
    int res=0;
    for(vector<int>::iterator it=nums.begin();it != nums.end();it++){
        res ^=(*it);
    }
    return res;
}

int main(){
    cout<<(2^10^2)<<endl;
    cout<<"Hello world!"<<endl;
    return 0;
}
