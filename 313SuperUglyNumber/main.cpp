//
// Created by leslie-fang on 2017/8/13.
//
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int nthSuperUglyNumber(int n, vector<int>& primes) {
    if(n==1){
        return 1;
    }
    int count=1, res=1, cnum=2, calculateNum=cnum;
    int end=primes.size()-1;
    while(count < n){
        calculateNum=cnum;
        int cpos=0;

        //vector<int>::iterator it=primes.begin();
        while(cpos <= end){
            if(calculateNum%(primes[cpos]) == 0){
                calculateNum = calculateNum/(primes[cpos]);
                if(calculateNum < primes[cpos]){
                    break;
                }
            }else{
                cpos++;
            }
        }
        if(calculateNum == 1){
            count++;
            if(count == n){
                res = cnum;
                break;
            }
        }
        cnum++;
    }
    return res;
}

int main(){
    cout<<"Hello world"<<endl;
    return 0;
}
