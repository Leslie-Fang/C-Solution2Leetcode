//
// Created by leslie-fang on 2017/6/11.
//
#include <iostream>
#include "reverseinteger.h"
#include <math.h>
using namespace std;

int reverse(int x) {
    long long res = 0;
    while(x) {
        res = res*10 + x%10;
        x /= 10;
    }
    return (res<INT_MIN || res>INT_MAX) ? 0 : res;


}

int main(){
    cout<<reverse(10987890)<<endl;
    return 0;
}
