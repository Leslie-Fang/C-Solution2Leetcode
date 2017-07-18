//
// Created by leslie-fang on 2017/7/18.
//
#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;

int maxArea(vector<int>& height) {
#first find the area of the widest area to contain the water
    int start=0,end=height.size()-1;
    int minus=min(height[start],height[end]);
    int mymax=minus*(end-start);
    while(1){
        minus=min(height[start],height[end]);
        mymax=max(mymax,minus*(end-start));
#only if higher we need to calculate the water containing again
        while(height[start]<=minus && start<end){start++;}
        while(height[end]<=minus && start<end){end--;}
        if(start>=end){
            break;
        }
    }
    return mymax;
}

int main(){
    vector<int> height;
    height.push_back(1);
    height.push_back(2);
    height.push_back(4);
    height.push_back(3);
    cout<<maxArea(height)<<endl;
    cout<<"hello world!"<<endl;
    return 0;
}