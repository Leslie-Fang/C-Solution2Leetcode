//
// Created by leslie-fang on 2017/8/15.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    //use priority_queue
    //priority_queue is heap
    priority_queue<int> q;
    for(vector<int>::iterator it=nums.begin();it !=nums.end();it++){
        q.push((*it));
    }
    //pop the lagerest number
    for(int i=1;i<k;i++){
        q.pop();
    }
    return q.top();
}

int main(){

    cout<<"Hello world!"<<endl;
    return 0;
}

