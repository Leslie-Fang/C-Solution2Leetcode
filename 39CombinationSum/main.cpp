//
// Created by leslie-fang on 2017/9/6.
//
#include<iostream>
#include<vector>
using namespace std;

void push(vector<vector<int> > &res,vector<int> &subres,vector<int>& candidates,int target,int point){
    if(!target){
        res.push_back(subres);
        return;
    }
    for(int i=point;i<candidates.size()&&target>=candidates[i];i++){
        subres.push_back(candidates[i]);
        push(res,subres,candidates,target-candidates[i],i);
        subres.pop_back();
    }
    return ;
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    vector<vector<int> > res;
    vector<int> subres;
    sort(candidates.begin(), candidates.end());
    push(res,subres,candidates,target,0);
    return res;

}

int main(){
    return 0;
}
