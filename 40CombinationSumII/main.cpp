//
// Created by leslie-fang on 2017/9/8.
//
#include<iostream>
#include<vector>
using namespace std;

void myFind(vector<vector<int> > &res,vector<int> &subres,vector<int>& candidates,int target,int point){
    if(!target){
        res.push_back(subres);
        return;
    }
    for(int i =point;i<candidates.size()&&target>=candidates[i];i++){
        //to avoid duplicated
        if (i == point || candidates[i] != candidates[i - 1]) {
            subres.push_back(candidates[i]);
            myFind(res,subres,candidates,target-candidates[i],i+1);
            subres.pop_back();
        }
    }

}

vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int> > res;
    vector<int> subres;
    sort(candidates.begin(),candidates.end());
    myFind(res,subres,candidates,target,0);
    return res;
}

int main(){
    cout<<"Hello world!"<<endl;
    int input[]={10, 1, 2, 7, 6, 1, 5};
    vector<int> vinput(input,input+7);
    int target = 8;
    vector<vector<int> > res = combinationSum2(vinput,target);
    vector<vector<int> >::iterator it=res.begin();
    for(it=res.begin();it !=res.end();it++){
        cout<<"1"<<endl;
    }
    return 0;
}