//
// Created by leslie-fang on 2017/6/24.
//
#include <iostream>
#include <vector>
using namespace std;

void deepSearch(vector<int>& nums, int S,int current,int size, int result,int sign,int &totalnums){
    if(current == (size-1)){
        if(sign == 0){
            result -=nums[current];
        }else{
            result +=nums[current];
        }
        if(result == S){
            totalnums++;
            return ;
        }
    }else{
        if(sign == 0){
            result -=nums[current];
        }else{
            result +=nums[current];
        }
        deepSearch(nums,S,current+1,size,result,0,totalnums);
        deepSearch(nums,S,current+1,size,result,1,totalnums);
    }
}

int findTargetSumWays(vector<int>& nums, int S) {
    int result=0;
    int current=0;
    int totalnums=0;
    for(vector<int>::iterator it=nums.begin(); it !=nums.end();it++){
        cout<<*it<<endl;
    }
    deepSearch(nums,S,current,nums.size(),result,0,totalnums);
    deepSearch(nums,S,current,nums.size(),result,1,totalnums);
    return totalnums;
}

int main(){
    int nums[]={1, 1, 1, 1, 1};
    int target=3;
    vector<int> input(nums,nums+5);
    cout<<findTargetSumWays(input,target)<<endl;
    cout<<"hello world"<<endl;
    return 0;
}
