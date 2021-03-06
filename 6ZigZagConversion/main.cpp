//
// Created by leslie-fang on 2018/1/3.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string convert(string s, int numRows);

int main(){
    string input="PAYPALISHIRING";
    string res=convert(input,3);
    cout<<res<<endl;
    return 0;
}

string convert(string s, int numRows) {
    if(numRows == 1)return s;
    int len = s.size(), k = 0, interval = (numRows<<1)-2;
    string res(len, ' ');
    for(int j = 0; j < len ; j += interval)
        res[k++] = s[j];
    for(int i = 1; i < numRows-1; i++)
    {
        int inter = (i<<1);
        for(int j = i; j < len; j += inter)
        {
            res[k++] = s[j];
            inter = interval - inter;
        }
    }
    for(int j = numRows-1; j < len ; j += interval)
        res[k++] = s[j];
    return res;
}

